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
    rep(i,N) cin >> A[i];
    ll ans = 0;
    bool possible = true;
    if (A[0] != 0) possible = false;
    
    ll prev = 0;
    rep(i,N - 1){
        if (A[i + 1] == prev + 1){
            ans += 1;
            prev = A[i + 1];
        }
        else if (A[i + 1] <= prev){
            ans += A[i + 1];
            prev = A[i + 1];
        }
        else{
            possible = false;
        }
    }
    if (possible) cout << ans << endl;
    else cout << -1 << endl;
}