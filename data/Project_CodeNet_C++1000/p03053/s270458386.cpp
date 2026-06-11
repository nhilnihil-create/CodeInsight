#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int visited[1000][1000];
int r,c;
char grid[1000][1000];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool isvalid(int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}
int32_t main() {
    nitin;
    cin>>r>>c;
    queue<pair<int,int>>q;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='#') {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    int cnt=0;
    while(true)
    {
        cnt++;
        queue<pair<int,int>>nq;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int a=x+dx[i];
                int b=y+dy[i];
                if(isvalid(a,b) && !visited[a][b])
                {
                    nq.push({a,b});
                    visited[a][b]=1;
                }
            }
        }
        q=nq;
        if(q.empty())
            break;
    }
    cout<<cnt-1<<endl;
    return 0;
}