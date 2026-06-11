#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll H,W;

bool onBoard(ll y,ll x){
    if(y>=0&&y<H&&x>=0&&x<W){
        return true;
    }
    return false;
}

int main() {
    cin >> H >> W;
    vector<string> S(H);
    
    for(int i=0;i<H;i++){
        cin >> S[i];
    }

    int dy[] = {1,0,-1,0};
    int dx[] = {0,1,0,-1};
    ll d[H][W];
    memset(d,-1,sizeof(d));
    d[0][0] = 1;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll t = q.front();q.pop();
        ll y = t/W;
        ll x = t%W;
        for(int i=0;i<4;i++){
            ll ny = y+dy[i];
            ll nx = x + dx[i];
            if(!onBoard(ny,nx)){
                continue;
            }
            if(d[ny][nx] != -1 || S[ny][nx] == '#'){
                continue;
            }
            d[ny][nx] = d[y][x] +1;
            q.push(ny*W+nx);
        }
    }
    if(d[H-1][W-1] ==-1){
        cout << -1 << endl;
        return 0;
    }

    ll ans =0;
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){
        if(S[i][j] =='.'){
            ans++;
        }
    }
    cout << ans -d[H-1][W-1] << endl;
    return 0;
}