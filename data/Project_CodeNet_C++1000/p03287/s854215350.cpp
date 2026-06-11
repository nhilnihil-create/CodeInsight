#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, M; cin >> N >> M;
    vector<ll> a(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<ll> s(N+1);
    s[0] = 0;
    for (ll i = 0; i < N; i++) {
        s[i+1] = (s[i] + a[i]) % M;
    }

    map<ll,ll> m;
    for (ll i = 0; i < N+1; i++) {
        if(m.count(s[i])){
            m[s[i]]++;
        }
        else{
            m[s[i]] = 1;
        }
    }

    ll ans = 0;
    for (auto v : m){
        ll c = v.second;
        ans += c * (c-1) / 2;
    }
    printf("%lld\n", ans);

}