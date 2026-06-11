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
    vector<int> S;
    ll M = 100005;
    vector<bool> prime(M, true);
    prime[1] = false;
    for (ll i = 2; i*i < M; i++) {
        if(prime[i] == false) continue;
        ll j = 2 * i;
        while(j < M){
            prime[j] = false;
            j += i;
        }
    }

    for (int i = 3; i < M; i+=2) {
        if(prime[i] && prime[(i+1)/2]){
            S.push_back(i);
        }
    }

    int Q;
    cin >> Q;
    int l, r;
    int ans;
    for (ll i = 0; i < Q; i++) {
        cin >> l >> r;
        ans = lower_bound(ALL(S), r+1) - lower_bound(ALL(S), l);
        printf("%d\n", ans);
    }

}