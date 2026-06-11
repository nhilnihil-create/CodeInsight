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

    vector<ll> S(N+1);
    S[0] = 0;
    for (int i = 0; i < N; i++) {
        S[i+1] = S[i] + A[i];
    }
    map<ll,ll> B;
    for (int i = 0; i < N+1; i++) {
        if(B.count(S[i])){
            B[S[i]]++;
        }
        else{
            B[S[i]] = 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < N+1; i++) {
        ans += B[S[i]] * (B[S[i]] - 1) / 2;
        B[S[i]] = 0;
    }

    printf("%lld\n", ans);
}