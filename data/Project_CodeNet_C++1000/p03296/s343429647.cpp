#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define Rep(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SMALLPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
using vc=vector<char>;
using vvc=vector<vector<char>>;
const int inf=1000000007;
const int mod=1000000007;
void chmin(auto &a,auto b){if(b<a)a=b;}
void chmax(auto &a,auto b){if(a<b)a=b;}
int main(){
  int n,ans=0,k=0;cin>>n;
  vi v(n);
  rep(i,n)cin>>v[i];
  rep(i,n-1){
    if(v[i]==v[i+1])k++;
    else{
      ans+=(k+1)/2;
      k=0;
    }
  }
  ans+=(k+1)/2;
  cout<<ans<<endl;
}