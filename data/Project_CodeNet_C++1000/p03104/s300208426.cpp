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
     ll a,b;
     cin >> a>>b;
     ll A,B;
     if(a%2==0&&b%2==0){
          if((b-a)/2%2==0){
               cout << b <<endl;
               return 0;
          }
          else {
               ll ans = b^1;
               cout << ans <<endl;
               return 0;
          }
     }
     if(a%2==0&&b%2==1){
          if((b-a+1)/2%2==0){
               cout << 0 <<endl;
               return 0;
          }
          else {
               cout << 1 <<endl;
               return 0;
          }
     }
     if(a%2==1&&b%2==0){
          if((b-1-a)/2%2==0){
               ll ans = a^b;
               cout << ans <<endl;
               return 0;
          }
          else {
               ll ans = a^b^1;
               cout << ans <<endl;
               return 0;
          }
     }
     if(a%2==1&&b%2==1)
     {
          if((b-a)/2%2==0){
               cout << a<<endl;
               return 0;
          }
          else{
               ll ans = a^1; 
               cout << ans <<endl;
          return 0;}
     }
}