#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)

typedef long long ll;
///vector<pair<string, int>>;

int main(){
 ll n, begin;
 cin >> n >> begin;
 vector<ll> x;
 rep(i, n) {
   ll y;
   cin >> y;
   x.push_back(y);
 }
 x.push_back(begin);
 sort(x.begin(), x.end());

 ll ans = x[1]-x[0];
 ll size = x.size();
 
 for(int i = 1; i < size-1; i++){
   ans = gcd(ans, x[i+1]-x[i]);
 }

 cout << ans << endl;
}
