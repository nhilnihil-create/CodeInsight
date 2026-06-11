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
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    vector<llll> X(N); //A+B と index
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        X[i].first = A[i] + B[i];
        X[i].second = i;
    }

    sort(ALL(X), greater<llll>());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if(i%2 == 0){
            ans += A[X[i].second];
        }
        else{
            ans -= B[X[i].second];
        }
    }
    printf("%lld\n", ans);
}
