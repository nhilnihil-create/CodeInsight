#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> t(N+1, 0), x(N+1, 0), y(N+1, 0);
    rep(i, 0, N) cin >> t[i+1] >> x[i+1] >> y[i+1]; 
    rep(i, 0, N){
        ll dx = abs(x[i+1] - x[i]);
        ll dy = abs(y[i+1] - y[i]);
        ll dt = t[i+1] - t[i];
        if((dy + dx) % 2 != dt % 2 || dx + dy > dt){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}