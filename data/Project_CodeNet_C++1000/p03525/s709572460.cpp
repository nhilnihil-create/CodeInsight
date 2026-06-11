#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
string strReplace(string s,string target, string replacement){
    if (!target.empty()) {
      std::string::size_type pos = 0;
      while ((pos = s.find(target, pos)) != std::string::npos) {
        s.replace(pos, target.length(), replacement);
        pos += replacement.length();
      }
    }
    return s;
}
const ll MOD = 1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair

bool DEBUG = 0;

bool func(int a, int b){
  return abs(a-12)>abs(b-12);
}

int main(){
  int N; cin>>N;
  int t[N+1];
  t[0] = 0;
  for(int i=1;i<=N;++i){
    cin >> t[i];
  }
  sort(t+1,t+N+1,func);
  int d[N+2];
  d[0] = 0;
  d[N+1] = 24;
  bool right = true;
  for(int i=1;i<=N;++i){
    if(right){
      if(t[i]<=12){
        d[i] = t[i];
      }else{
        d[i] = 24-t[i];
      }
    }else{
      if(t[i]<=12){
        d[i] = (24-t[i]);
      }else{
        d[i] = t[i];
      }
    }
    right = !right;
  }
  sort(d,d+N+1);
  int s = 100;
  for(int i=0;i<=N;++i){
    chmin(s, (d[i+1]-d[i])%24 );
  }
  cout << s << "\n";
}