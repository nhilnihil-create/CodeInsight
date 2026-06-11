#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

map<ll,ll> pfmp; //各素因数の冪指数の総和を格納
vector<ll> pfv(0); //異なる素因数を昇順に格納

void pf(ll N){
  ll n=N;
  if(n<=0) return;
  if(n%2==0){
    if(pfmp[2]==0) pfv.push_back(2);
    while(n%2==0){
      n/=2;
      pfmp[2]++;
    }
  }
  if(n==1) return;
  for(ll i=3;i<=sqrt(N);i+=2){
    if(n%i==0){
      if(pfmp[i]==0) pfv.push_back(i);
      while(n%i==0){
        n/=i;
        pfmp[i]++;
      }
    }
  }
  if(n!=1){
    if(pfmp[n]==0){
      pfv.push_back(n);
      pfmp[n]=1;
    }
    else{
      pfmp[n]++;
    }
  }
  //sort(all(pfv));
}

int kosuu[100];

int main(){
  int n; cin >> n;
  rep(i,n){
    pf(i+1);
  }
  ll ans=0;
  for(auto c:pfmp){
    if(c.second>=74) kosuu[74]++;
    if(c.second>=24) kosuu[24]++;
    if(c.second>=14) kosuu[14]++;
    if(c.second>=4) kosuu[4]++;
    if(c.second>=2) kosuu[2]++;
  }
  ans+=kosuu[74];
  ans+=(kosuu[2]-1)*kosuu[24];
  ans+=(kosuu[4]-1)*kosuu[14];
  ans+=(kosuu[4])*(kosuu[4]-1)/2*(kosuu[2]-2);
  cout << ans << endl;
}