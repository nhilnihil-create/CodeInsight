#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 998244353
const int MAX = 510000;

int main() {
 int N,M;
 cin>>N>>M;
 ll P=N*100ll+M*1800ll; 
 ll ans=1;
 rep(i,M){ans*=2ll;}
 cout<<ans*P; 
}