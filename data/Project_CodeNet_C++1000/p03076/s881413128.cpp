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
   vector<int>x;
   rep(i,5){
   int a,b,c,d,e;
   cin>>a>>b>>c>>d>>e;
   x.push_back(a);
   x.push_back(b);
   x.push_back(c);
   x.push_back(d);
   x.push_back(e);
   }
   int ans=0,ama=10;
   rep(i,5){
       if(x[i]%10==0) ans+=x[i];
       else {ans+=(x[i]/10*10)+10;
           ama=min(x[i]%10,ama);
       }
   }
   if(ama!=10) ans-=(10-ama);
   cout<<ans <<endl;

}