#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    vector<ll> vec_copy(N);
    rep(i,N){
        vec_copy[i] = max(vec[i], -1 * vec[i]);
    }
    sort(all(vec_copy));
    int count = 0;
    rep(i,N){
        if (vec[i] <= 0) count++;
    }
    ll ans = 0;
    if (count % 2 == 0){
        rep(i,N){
            ans += vec_copy[i];
        }
    }
    else{
        ans += vec_copy[0] * -1;
        rep(i,N - 1){
            ans += vec_copy[i + 1];
        }
    }
    cout << ans << endl;
}

