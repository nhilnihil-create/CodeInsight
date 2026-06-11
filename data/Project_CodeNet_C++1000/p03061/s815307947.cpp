#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pnn=pair<int ,int>;

#define ft first
#define sd second
#define fn front
#define pb push_back
#define it insert
#define count ct
#define si(v) int((v).size())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sot(x) sort(x.begin(), x.end())
#define rese(x) reverse(x.begin(), x.end())
#define vnn(x,y,s,name) vector<vector<int>> name(x, vector<int>(y,s))
#define mse(x) memset(x, 0, sizeof(x))
#define mii(x,y,z) min(x,min(y,z))
#define maa(x,y,z) max(x,max(y,z))

string yes="Yes",no="No";

int main() {
   int n;
   cin>>n;
   vin a(n);
   rep(i,n) cin>>a[i];
   sot(a);
   vin dp(n+1,0);
   queue<int> s;
   rep(i,n){
       dp[i+1]=gcd(dp[i],a[i]);
       
       
       rep(j,s.size()+1){
           int x=s.fn();
           //cout<<x<<" "<<i<<endl;
           s.pop();
           x=gcd(x,a[i]);
           if(x!=1) s.push(x);
       }
       if(dp[i]!=dp[i+1]&&dp[i]!=1) s.push(dp[i]);
       //cout<<dp[i]<<endl;
       //cout<<dp[i+1]<<endl;
   }
   int ans=1;
   //cout<<endl;
   rep(i,s.size()){
       int y=s.fn();
       //cout<<y<<endl;
       s.pop();
       ans=max(ans,y);
   }
   cout<<ans<<endl;
  
}