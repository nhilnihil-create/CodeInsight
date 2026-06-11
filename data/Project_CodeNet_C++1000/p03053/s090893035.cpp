#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for (int i=a; i<b; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll H,W; cin >> H >> W;
    vector <string> Grid(H);
    loop(i,0,H) cin >> Grid[i];
    queue <pair <pair<int, int>, int> > Q;
    vector < vector <bool> > visited(H, vector<bool> (W, false));
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            if (Grid[i][j]=='#') {
                Q.push({{i,j},0});
                visited[i][j]=true;
            }
        }
    }
    int ans=0;
    while (!Q.empty())
    {
        pair <int,int> cur=Q.front().first;
        int op=Q.front().second;
        ans=max(ans,op);
        Q.pop();
        if (cur.first>0 && !visited[cur.first-1][cur.second]) {
            visited[cur.first-1][cur.second]=true;
            Q.push({{cur.first-1, cur.second}, op+1});
        }
        if (cur.second>0 && !visited[cur.first][cur.second-1]) {
            visited[cur.first][cur.second-1]=true;
            Q.push({{cur.first, cur.second-1}, op+1});
        }
        if (cur.first<H-1 && !visited[cur.first+1][cur.second]) {
            visited[cur.first+1][cur.second]=true;
            Q.push({{cur.first+1, cur.second}, op+1});
        }
        if (cur.second<W-1 && !visited[cur.first][cur.second+1]) {
            visited[cur.first][cur.second+1]=true;
            Q.push({{cur.first, cur.second+1}, op+1});
        }
    }
    cout << ans << "\n";
    return 0;
}