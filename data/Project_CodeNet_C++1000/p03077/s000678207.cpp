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
    vector<ll> A(5, 0);
    rep(i, 5) cin >> A[i];
    sort(A.begin(), A.end());
    ll ans = 5;
    if(N % A[0] == 0){
        ans += N / A[0] - 1;
    }
    else{
        ans += N / A[0];
    }
    cout << ans << endl;
}