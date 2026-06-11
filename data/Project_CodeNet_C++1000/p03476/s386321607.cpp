#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
int dh[4] = {-1, 0, 0, 1};
int dw[4] = {0, -1, 1, 0}; 
using P = pair<int, int>;
const double pi = acos(-1.0);

using Graph = vector<vector<ll>>;


ll prime[10000000];
vector<bool> is_prime;

//篩です
vector<bool> seive(ll n){
  ll  p=0;
  rep(i,n+1)is_prime[i]=true;
  is_prime[0]=is_prime[1]=false;
  Rep(i,2,n+1){
    if(is_prime[i]){
      prime[p++]=i;
      for(ll j=2*i;j<=n;j+=i)is_prime[j]=false;
    }
  }
  return is_prime;//今回はどの数が素数か？が重要なので素数で有るものをtrueにしたものを返す
}

int main(){
  //input1&prepare
  ll q;
  cin>>q;
  vector<bool>isp;

  is_prime.resize(100002);
  isp=seive(100002);
  
  vector<ll>cnt(100002);//せっかくふるいにかけてもl~rの範囲で一個一個素数or素数じゃないをすると1e10となりさすがにまずい。
  //ここはその数字までに条件を満たす数がいくつあったかをカウントする
  rep(i,100002){
    if(isp[i]&&isp[(i+1)/2])cnt[i]+=cnt[i-1]+1;
    else cnt[i]=cnt[i-1];
  }

  //output 
  ll l,r;
  rep(i,q){
    cin>>l>>r;
    ll ans=cnt[r]-cnt[l-1];
    cout<<ans<<endl;
    
  }
    
    
  return 0;
}
