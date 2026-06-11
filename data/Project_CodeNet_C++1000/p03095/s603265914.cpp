#include<bits/stdc++.h>
using namespace std;
    static const double pi = 3.141592653589793;
 typedef pair<int64_t,int64_t> P;
#define rep(i, n) for (int i = 0; i < (n); i++)
 #define all(v) (v).begin(),(v).end()
 using ll = long long;
using Graph = vector<vector<int>>;
const int MAX = 510000;
const int MOD = 1000000007;
 const int NINE=1000000000;
 
 
int main(){
ll N;
  cin>>N;
string s;
  cin>>s;
  vector<ll>ab(26);
  ll t=1;
  rep(i,N){
  
    
    if(s[i]==s[i-1]) t++;
    else{
    ll k=s[i-1]-'a';
    ab[k]=ab[k]+t;
    t=1;
    }
    
  
  }
    ll k=s[N-1]-'a';
    ab[k]=ab[k]+t;
    
  ll ans=1;
  rep(i,26){
  ans=(ab[i]+1)*ans%1000000007;
  
  }
  cout<<ans-1;

  
  
}