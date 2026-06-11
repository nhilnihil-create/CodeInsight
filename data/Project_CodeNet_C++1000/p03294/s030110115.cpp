#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define INF 10000000000000000LL
#define ll  long long 
const int inf =INT_MAX;
const int MAX=3e5+9;
const ll MOD=1e9+7;
const int TOT_PRIMES=1e6+9;
const int MAX_A=71;
const int LN=20;
using namespace std;

int main(){
    int N; cin >> N;
    vector <ll> a(N);
    ll ans = 0;
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
        ans += a.at(i);
    }
    ans -= N;
    cout << ans << "\n";
    return 0;
}