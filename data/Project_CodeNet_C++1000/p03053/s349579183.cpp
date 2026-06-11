#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h)cin >> a[i];

    queue<P> q;
    rep(i,h)rep(j,w){
        if(a[i][j] == '#') q.push(P(i,j));
    }

    ll ans = 0;
    bool flag=true;

    while(1){
        rep(i,h){
            if(flag){
                rep(j,w){
                    if(a[i][j]== '.'){
                        flag = false;
                        break;
                    }
                }
            }
        }
        queue<P> nq;
        swap(q,nq);
        while(!nq.empty()){
            P u = nq.front();
            nq.pop();
            int x=u.first, y=u.second;
            rep(i,4){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0||ny<0||nx>=h||ny>=w)continue;
                if(a[nx][ny]=='#')continue;
                a[nx][ny] = '#';
                q.push(P(nx,ny));
            }
        }

        if(flag)break;
        else{
            flag = true;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}