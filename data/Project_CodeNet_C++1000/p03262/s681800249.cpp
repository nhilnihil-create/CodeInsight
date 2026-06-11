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
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main() {
     int n,X;
     cin >> n >> X;
     vector<int> x(n);
     rep(i,n) cin >> x[i];
     int a  = abs(X-x[0]);
     rep(i,n-1){
         a=  gcd(a,abs(x[i+1]-x[i]));
     }
     cout << a<<endl;
}