#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;

    vector<ll> A(N, 0);
    rep(i,N) cin >> A[i];

    rep(i,N - 1){
        if(A[i] < 0){
            A[i] = -A[i];
            A[i + 1] = -A[i + 1];
        }
    }
    ll cnt = 0;
    rep(i,N){
        if(A[i] >= 0){
            cnt++;
        }
    }
    A[N - 1] = abs(A[N - 1]);
    sort(A.begin(),A.end());
    if(cnt != N){
        rep(i,N) ans += llabs(A[i]);
        ans -= A[0] * 2;

    }
    else{
        rep(i,N) ans += A[i];
    }

    cout << ans << endl;

}