#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,H,W;
    cin >> N >> H >> W;
    int cnt = 0;
    rep(i,0,N){
        int h,w;
        cin >> h >> w;
        if(h >= H && w >= W)cnt++;
    }
    cout << cnt << endl;
}