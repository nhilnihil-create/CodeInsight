#include <bits/stdc++.h>  
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define cout(val) cout << (val) << endl
using namespace std;
typedef long long ll;

int main(){
    int h, w, b = 0, ty, tx, dist = 0;
    cin >> h >> w;
    vector<ll> c(h);
    char t;
    rep(i, h) rep(j, w){
        cin >> t;
        if(t=='#'){
            c[i] |= 1ll<<j;
            ++b;
        }
    }
    queue<pair<int,int>> que1, que2;
    que2.push(make_pair(0, 0));
    vector<ll> seen(h);
    seen[0] = 1;
    vector<int> dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};
    pair<int, int> p;
    while(!que2.empty()){
        que2.swap(que1);
        ++dist;
        while(!que1.empty()){
            p = que1.front();
            que1.pop();
            rep(i, 4){
                ty = p.first + dy[i];
                tx = p.second + dx[i];
                if(ty==h-1 && tx==w-1) goto esc;
                if(ty==-1||tx==-1||ty==h||tx==w||seen[ty]&1ll<<tx||c[ty]&1ll<<tx) continue;
                que2.push(make_pair(ty, tx));
                seen[ty] |= 1ll<<tx;
            }
        }
    }
    cout(-1);
    return 0;
    esc:
    cout(h*w - dist - b - 1);
}
