#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<ll> F(N), B(N);
    F[0] = A[0];
    B[N-1] = A[N-1];

    for (int i = 1; i < N; i++) {
        F[i] = __gcd(A[i], F[i-1]);
    }
    for (int j = N-2; j >= 0; j--) {
        B[j] = __gcd(A[j], B[j+1]);
    }

    ll ans;
    ans = max(F[N-2], B[1]);
    for (int i = 1; i < N-1; i++) {
        ans = max(ans, __gcd(F[N-i-2], B[N-i]));
    }

    printf("%lld\n", ans);


}
