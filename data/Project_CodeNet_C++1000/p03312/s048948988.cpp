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

int main(){
  ll ans=llmax;
  itn n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> s(n+1);
  rep(i,n) s[i+1]=s[i]+a[i];
  for(int i=2;i<n-1;i++){
    int itr1=lower_bound(all(s),s[i]/2)-s.begin();
    int itr2=lower_bound(all(s),(s[i]+s[n])/2)-s.begin();
    vector<ll> b;
    if( abs(s[itr1]-(s[i]-s[itr1]))<abs(s[itr1-1]-(s[i]-s[itr1-1]))){
      b.push_back(s[itr1]);
      b.push_back(s[i]-s[itr1]);
    }
    else{
      b.push_back(s[itr1-1]);
      b.push_back(s[i]-s[itr1-1]);
    }
    if( abs((s[itr2]-s[i])-(s[n]-s[itr2]))< abs((s[itr2-1]-s[i])-(s[n]-s[itr2-1])) ){
      b.push_back(s[itr2]-s[i]);
      b.push_back(s[n]-s[itr2]);
    }
    else{
      b.push_back(s[itr2-1]-s[i]);
      b.push_back(s[n]-s[itr2-1]);
    }
    sortt(b);
    chmin(ans,b[b.size()-1]-b[0]);
  }  
  cout << ans << endl;
}