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
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll K;
    cin >> K;
    vector<ll> a(K);
    for (ll i = 0; i < K; i++) {
        cin >> a[i];
    }
    if(a[K-1] != 2){
        printf("-1\n");
        return 0;
    }
    ll L = 2; ll tmpl;
    ll S = 2; ll tmps;
    for (ll i = K-1; i >= 1; i--) {
        tmpl = ((L+a[i]-1) / a[i-1]) * a[i-1];
        if(tmpl < S){
            printf("-1\n");
            return 0;
        }

        tmps = ((S-1) / a[i-1]) * a[i-1] + a[i-1];
        if(tmps >= L + a[i]){
            printf("-1\n");
            return 0;
        }
        L = tmpl;
        S = tmps;
    }
    L = L + a[0] - 1;
    S = S;
    printf("%lld %lld\n", S, L);

}