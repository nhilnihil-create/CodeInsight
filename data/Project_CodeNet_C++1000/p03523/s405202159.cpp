#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define repr(i,n) for(int i=(n);i>=0;--i)
#define int long long
#define itn int
#define pb push_back
#define m_p make_pair
#define m_t make_tuple
#define p_p(a,b) pb(m_p(a,b))
#define all(a) a.begin(),a.end()
#define SORT(a) sort(all(a))
#define RSORT(a) sort(all(a),greater<>)
#define UNIQUE(a) a.erase(unique(all(a)),a.end())
#define SZ(a) a.size()
#define ENDL cout<<endl
#define debg(a) cout<<#a<<" "<<a<<endl
#define debgp(a) cout<<#a<<" "<<a.fi<<" "<<a,se<<endl
#define call(a) for(auto i:a)cout<<i<<" ";cout<<endl
#define show(a) for(const auto&y:a){for(const auto&x:y)cout<<x<<" ";cout<<endl;}
#define fi first
#define se second
#define V vector
#define P pair
#define PQ priority_queue
typedef long long ll;
typedef string str;
typedef vector<ll> VL;
typedef pair<ll,ll> PL;
typedef vector<PL> VP;
const long long INF = 1LL<<60;
const long long MOD = 1e9+7;
void Yes(){cout<<"Yes"<<endl;}
void No(){cout<<"No"<<endl;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
template<class T>T gcd(T a,T b){return (b==0?a:gcd(b,a%b));}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*a;}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  str s;
  cin>>s;
  str akiba="#KIHBR#";
  bool ans=true;
  s='#'+s+'#';
  for(int i=1;i<SZ(s);++i){
    if(s[i]=='A' && i!=SZ(s)-1 && s[i+1]=='A')ans=false;
    if(s[i]=='K' && (s[i-1]!='#' && s[i-1]!='A'))ans=false;
    if(s[i]=='K' && s[i+1]!='I')ans=false;
    if(s[i]=='I' && s[i+1]!='H')ans=false;
    if(s[i]=='H' && (s[i+1]!='A' && s[i+1]!='B'))ans=false;
    if(s[i]=='B' && (s[i+1]!='A' && s[i+1]!='R'))ans=false;
    if(s[i]=='R' && (s[i+1]!='#' && s[i+1]!='A'))ans=false;
  }
  for(auto itr=s.begin();itr<s.end();){
    if(*itr=='A')s.erase(itr);
    else itr++;
  }
  //debg(s);debg(akiba);debg(ans);

  cout<<(s==akiba&&ans?"YES":"NO")<<endl;
  
  
  
  return 0;
}
