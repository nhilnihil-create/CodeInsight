#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> p(N), q(N+1);
    rep(i, 0, N){
        cin >> p[i];
        q[p[i]] = i;
    }
    ll mx = 1, pre = -1, tmx = 0;
    rep(i, 1, N+1){
        if(pre < q[i]){
            tmx++;
            pre = q[i];
            mx = max(tmx, mx);
        }else{
            pre = q[i];
            tmx = 1;
        }
        // cerr << "q[i] : " << q[i] << ", tmx : " << tmx << endl;
    }
    cout << N - mx << endl;
    return 0;
}