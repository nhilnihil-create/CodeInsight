#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    if(K == 0){
        ll an = 0;
        for (ll i = 0; i < N; i++) {
            an += A[i];
        }
        printf("%lld\n", an);
        return 0;
    }
    vector<ll> two(42);
    two[0] = 1;
    for (ll i = 1; i < 42; i++) {
        two[i] = two[i-1] * 2;
    }

    vector<ll> x(42, 0);
    for (ll i = 0; i < N; i++) {
        for (ll j = 1; j < 42; j++) {
            if(A[i] & two[41-j]){
                x[j]++;
            }
        }    
    }

    vector<ll> dp0(42, 0), dp1(42, 0);
    ll d;
    for (ll i = 1; i < 42; i++) {
        if(K & two[41-i]){
            d = i;
            break;
        }
    }
    dp1[d] = 0;
    dp0[d] = (N - 2 * x[d]) * two[41-d];
    for (ll i = d+1; i < 42; i++) {
        dp1[i] = dp1[i-1] + max((N - 2 * x[i]) * two[41-i], zero);
        if(K & two[41-i]){
            dp1[i] = max(dp1[i], dp0[i-1]);
            dp0[i] = dp0[i-1] + (N - 2 * x[i]) * two[41-i];
        }
        else{
            dp0[i] = dp0[i-1];
        }
    }

    ll ans = max(dp0[41], dp1[41]);
    for (ll i = 0; i < N; i++) {
        ans += A[i];
    }
    printf("%lld\n", ans);

}