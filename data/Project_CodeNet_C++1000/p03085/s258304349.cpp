#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
 
ll MOD = 1000000007;
ll INF =1<<29;
ll dp[100100];
 
int main() {
     char b;
     cin >>b;
     if(b=='A'){
         cout << 'T' <<endl;
         return 0;
     }
     else if(b=='G'){
         cout << 'C' <<endl;
         return 0;
     }
     else if(b=='T'){
         cout << 'A' <<endl;
         return 0;
     }
     cout << 'G' <<endl;
}
  