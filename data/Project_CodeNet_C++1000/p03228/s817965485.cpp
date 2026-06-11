#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;



int main(){
   int a,b,k;
   cin >> a>>b>>k;
   rep(i,k/2){
       if(a%2==1){
           a--;
           a/=2;
           b+=a;
           if(b%2==1) {b--,b/=2;a+=b;}
           else{
               b/=2;
               a+=b;
           }
       }
       else{
           a/=2;
           b+=a;
           if(b%2==1) {b--,b/=2;a+=b;}
           else{
               b/=2;
               a+=b;
           }
       }
   }
   if(k%2==1){
       if(a%2==1) {a--;a/=2;b+=a;}
       else {a/=2,b+=a;}
   }
   cout << a<< ' ' <<b <<endl;

}