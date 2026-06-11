#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll a, ll b){
   if(b == 0) return a;
   return gcd(b, a % b);
}
int main(){
   int n; cin >> n;
   vector<ll> a(n);
   rep(i,n) cin >> a[i];
   vector<ll> b(n + 1);
   b[0] = 0;
   for(int i = 1; i < n + 1; i++){
      b[i] = a[i - 1] + b[i - 1];
   }
   sort(b.begin(), b.end());
   ll ans = 0;

   for(int i = 0; i < n + 1; i++){
      ll count = 1;
         if(b[i] == b[i + 1]){
            while(i < n && b[i] == b[i + 1]){
               count++;
               i++;
            }
         }
         ans += count * (count - 1) / 2;
         count = 1;
   }
   cout << ans << endl;

}