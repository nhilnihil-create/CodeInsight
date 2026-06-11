#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> D(N), v;
    vector<ll> st(13, 0);
    st[0]++;
    ll def = 12;
    bool f = false;
    rep(i, 0, N){
        cin >> D[i];
        st[D[i]]++;
    }
    ll bmax = 0;
    rep(i, 1, 12){
        if(st[i] > 0){
            if(st[i] == 1){
                bmax++;
                v.push_back(i);
            }else if(st[i] > 2){
                f = true;
            }
        }
    }
    if(st[0] == 1) v.push_back(0);
    else if(st[0] > 1) f = true;
    if(st[12] == 1) v.push_back(12);
    else if(st[12] > 1) f = true;
    rep(i, 1, 12){
        if(st[i] == 2){
            v.push_back(i);
            v.push_back(24 - i);
        }
    }
    if(f){
        cout << 0 << endl;
        return 0;
    }
    ll n = v.size();
    // rep(i, 0, n) cerr << v[i] << " ";
    // cerr << endl;
    ll ans = 0;
    for(int bit = 0; bit < 1<<bmax; bit++){
        ll mn = def;
        rep(i, 0, n-1){
            rep(j, i+1, n){
                ll di = v[i], dj = v[j];
                if((i < bmax) && (bit & (1<<i))) di = (24 - di);
                if((j < bmax) && (bit & (1<<j))) dj = (24 - dj);
                // cerr << di << "," << dj << endl;
                mn = min(mn, min(abs(di - dj), 24 - abs(di - dj)));
            }
        }
        ans = max(ans, mn);
    }
    cout << ans << endl;
    return 0;
}