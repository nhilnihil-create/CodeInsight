#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h,w;
char s[55][55];
ll dist[55][55];
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main(){
    cin >> h >> w;
    ll countw=0;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin >> s[i][j];
            if(s[i][j]=='.') countw++;
            dist[i][j]=-1;
        }
    }
    queue<pair<ll,ll>> que;
    dist[0][0]=1;
    que.push(make_pair(0,0));
    while(!que.empty()){
        auto v=que.front();
        que.pop();
        for(ll i=0;i<4;i++){
            pair<ll,ll> nv;
            nv.first=v.first+dx[i];
            nv.second=v.second+dy[i];
            if(nv.first<0||nv.first>=h||nv.second<0||nv.second>=w) continue;
            if(s[nv.first][nv.second]=='#'||dist[nv.first][nv.second]!=-1) continue;
            dist[nv.first][nv.second]=dist[v.first][v.second]+1;
            que.push(nv);
        }
    }
    ll res;
    if(dist[h-1][w-1]==-1) res=-1;
    else res=countw-dist[h-1][w-1];
    cout << res << endl;
}
