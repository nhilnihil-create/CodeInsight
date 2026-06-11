#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    for (ll i = K + 1; i <= N; i++){
        if (K == 0){
            ans--;
        }
        if (N % i < K){
            ans += (N / i) * (i - K);
        }
        else{
            ans += (N / i) * (i - K);
            ans += (N % i - K + 1);
        }
    }
    cout << ans << endl;
}