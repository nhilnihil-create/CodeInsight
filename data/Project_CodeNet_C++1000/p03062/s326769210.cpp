#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll gcd(ll a,ll b) {return  b ? gcd(b,a%b) : a;}
const long long INF = 1LL << 60;
const int mod = 1000000007;
const double PI = acos(-1.0);
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


int main () {
     int n ;
     cin >> n;
     vector<int>a(n);
     rep(i,n)cin >>a[i];
     vector<int>b(n);
     rep(i,n) b[i] =abs(a[i]);
     sort(b.begin(),b.end());
     int cnt=0;
     rep(i,n){
          if(a[i]<0) cnt++;
     }
     ll ans = 0;
     rep(i,n) ans+=b[i];
     if(cnt%2==0) cout << ans <<endl;
     else cout << ans - 2*b[0] <<endl;
}