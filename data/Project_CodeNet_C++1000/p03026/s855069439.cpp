#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm> // sort
#include <math.h>

#define DEBUG 0

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
                    //999999997000000003
                    //1000000000000000000

using namespace std;

int solve(){
    int N;
    cin >> N;
    vector <vector <int> > g(N);
    vector <int> c(N);
    vector <int> res(N);
    vector <int> used(N,0);

    REP(i, N-1)
    {
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    REP(i, N)cin >> c[i];

    sort(c.rbegin(),c.rend());
    int isum = 0;

    for(int i = 1; i < N; ++i)
    {
        isum += c[i];
    }

    
    queue <ll> q;
    //0の根付き木としてcを降順に割り振る
    q.push(0);
    used[0] = 1;
    int cnt = 0;
    res[0] = c[cnt++];
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < g[cur].size(); ++i)
        {
            int tar = g[cur][i];
            if(used[tar])continue;
            used[tar] = 1;
            res[tar] = c[cnt++];
            q.push(tar);
        }
    }


    cout << isum << endl;

    for(auto v:res)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;

}

int main()
{
    solve();
    return 0;
}
