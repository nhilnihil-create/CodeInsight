#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<bitset>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<iterator>

using namespace std;
typedef pair<int, int> PA;
typedef priority_queue<int> PQ;
typedef vector<int> VE;
#define int long long
#define INF 1000000009
#define INFL 1000000000000000018
#define mod 1000000007
#define pb push_back
#define MAXN 100005

int n, m, toa[200010], tob[200010];
string s;
vector<int> G[200010];
bool used[200010];

signed main()
{
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
        if(s[a - 1] == 'A') toa[b]++;
        else tob[b]++;
        if(s[b - 1] == 'A') toa[a]++;
        else tob[a]++;
    }
    queue<int> que;
    for(int i = 1; i <= n; i++){
        if(toa[i] == 0 || tob[i] == 0){
            que.push(i);
            used[i] = true;
        }
    }
    int cnt = 0;
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        cnt++;
        for(int i = 0; i < (int)G[pos].size(); i++){
            int to = G[pos][i];
            if(!used[to]){
                if(s[pos - 1] == 'A') toa[to]--;
                else tob[to]--;
                if(toa[to] == 0 || tob[to] == 0){
                    used[to] = true;
                    que.push(to);
                }
            }
        }
    }
    if(cnt == n){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }

    return 0;
}
