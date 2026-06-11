#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n] = {};
    int d[n][m];
    memset(d,-1,sizeof(d));
    queue<pair<int,int>>q;
    f(n) {
        cin >> s[i];
        fr(j,0,m) {
            if (s[i][j]=='#') {
                q.push({i,j});
                d[i][j] = 0;
            }
        }
    }
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        f(4) {
            int nx = now.F + dx[i];
            int ny = now.S + dy[i];
            if (nx >= n || nx < 0 || ny >= m || ny < 0)continue;
            if (~d[nx][ny])continue;
            q.push({nx,ny});
            d[nx][ny] = d[now.F][now.S] + 1;
        }
    }
    int mx = 0;
    f(n){
        fr(j,0,m){
            mx = max(mx,d[i][j]);
        }
    }
    cout << mx << '\n';
}
