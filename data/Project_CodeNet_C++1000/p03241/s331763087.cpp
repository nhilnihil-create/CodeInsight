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
    ll N, M;
    cin >> N >> M;
    vector<ll> c;
    ll tmp = M;
    c.push_back(1);
    c.push_back(M);
    for (ll i = 2; i*i <= M; i++) {
        if(tmp % i == 0){
            c.push_back(i);
            c.push_back(M / i);
        }
    }
    sort(ALL(c), greater<ll> ());

    ll L = c.size();
    for (ll i = 0; i < L; i++) {
        if(N * c[i] <= M){
            printf("%lld\n", c[i]);
            return 0;
        }
    }


}