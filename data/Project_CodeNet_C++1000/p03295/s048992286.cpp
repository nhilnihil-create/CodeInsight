#include<bits/stdc++.h>
#define INF 1e7

using namespace std;
typedef long long int ll;

int main()
{
    int N,M; cin >> N >> M;
    vector<pair<int,int>>g;
    for(int i = 0; i < M; i++)
    {
        int a,b;cin >> a >> b;
        a--,b--;
        g.push_back(pair(b,a));
    }
    sort(g.begin(),g.end());
    int x = -1;
    int ans = 0;
    for(int i = 0; i < M; i++)
    {
        int a = g[i].second;
        int b = g[i].first;
        if(a <= x) continue;
        x = b - 1;
        ans++;
    }
    cout << ans << endl;
}