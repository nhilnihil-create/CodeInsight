#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
const int mod = 1000000007;

ll dp[100100];
int main() {
   int n,q;
   cin>>n>>q;
   string s;
   cin>>s;
   vector<int>a(n);
   rep(i,n-1){
       if(s[i]=='A'&&s[i+1]=='C'){
           a[i+1]++;
       }
   }
   vector<int>d(n);
   d[0] = a[0];
   rep(i,n-1){
       d[i+1] =d[i]+a[i+1];
   }
   rep(i,q){
       int l,r;
       cin>>l>>r;
       cout << d[r-1]-d[l-1] <<endl;
   }

}