#include<bits/stdc++.h>
#include<math.h>
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
    ll N, K, ans;
    float res;
    cin >> N >> K;
    vector <ll> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }
    N = N - K;
    res = float(N) / float(K - 1);
    ans = ceil(res);
    cout << ans + 1 <<"\n";
    return 0;
}