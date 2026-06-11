#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    vector<ll> B(N + 1);
    B[0] = 0;
    rep(i,N){
        B[i + 1] = B[i] + A[i];
    }
    map<ll,ll> mp;
    rep(i,N + 1){
        mp[B[i]]++;
    }
    ll ans = 0;
    for (map<ll,ll>::iterator itr = mp.begin(); itr != mp.end(); itr++){
        ans += (itr->second * (itr->second - 1)/ 2);
    }
    cout << ans << endl;
}