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
    ll N;
    cin >> N;
    vector <ll> a(N), b(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
        b.at(i) = a[i] - (i + 1);
    }
    sort(b.begin(), b.end());
    ll item = b[N/2];
    ll ans = 0;
    for(int i = 0; i <N; i++)
        ans += abs(a[i] - (i + 1 + item));
    cout << ans << "\n";
  return 0;
}