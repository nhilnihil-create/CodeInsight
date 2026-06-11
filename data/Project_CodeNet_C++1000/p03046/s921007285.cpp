#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

ll rui(ll a,ll n){
  ll ans=1;
  while(n>0){
    if(n&1) ans=ans*a%mod;
    a=a*a%mod;
    n/=2;
  }
  return ans;
}

int main(){
  itn m; cin >> m;
  int k; cin >> k;
  int mx=rui(2,m)-1;
  if((m==1&&k==1)||mx<k){
    cout << -1 << endl;
    return 0;
  }
  if(m==1&&k==0){
    cout << "0 0 1 1" << endl;
    return 0;
  }
  deque<int> q;
  q.push_back(k);
  rep(i,mx+1){
    if(i==k) continue;
    q.push_back(i);
    q.push_front(i);
  }
  q.push_back(k);
  while(q.size()){
    int ans=q.front();
    q.pop_front();
    cout << ans << " ";
  }cout << endl;
}