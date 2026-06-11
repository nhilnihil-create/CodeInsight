#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N;
    cin >> N;
    ll A, preA;
    cin >> A;
    if(A != zero){
        printf("-1\n");
        return 0;
    }
    preA = zero;
    ll ans = 0;
    for (ll i = 1; i < N; i++) {
        cin >> A;
        if (A == preA + 1) {
            ans++;
        }
        else if (A > preA + 1) {
            printf("-1\n");
            return 0;
        }
        else{
            ans += A;
        }
        preA = A;
    }

    printf("%lld\n", ans);


}