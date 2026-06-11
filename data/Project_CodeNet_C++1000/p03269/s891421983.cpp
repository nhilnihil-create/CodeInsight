#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define rrep(i,n) for(int i=1; i<=(n); ++i)
#define drep(i,n) for(int i=(n)-1; i>=0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define foreach(it, v) for(typeof(v.begin()) it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define v(T) vector<T>

typedef unsigned int uint;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef vector<pii> vpii;
typedef set<int> si;
typedef multiset<int> msi;
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename ...Args>inline ostream& operator<<(ostream&o,const tiii&t)
{o<<get<0>(t)<<' '<<get<1>(t)<<' '<<get<2>(t);return o;}

int  L;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> L;

  int N = 0;
  vi Ns;
  int LL = L;
  while (LL) {
    int d = 1 << N;
    if (LL&d) {
      Ns.pb(N);
      LL -= d;
    }
    ++N;
  }
  v(tiii) anss;
  rep(i, N-1) {
    anss.pb(tiii(i+1, i+2, 0));
    anss.pb(tiii(i+1, i+2, 1<<i));
  }
  drep(i, sz(Ns)) {
    if (Ns[i]+1 != N) {
      anss.pb(tiii(Ns[i]+1, N, LL));
    }
    LL += (1<<Ns[i]);
  }
  cout << N << " " << sz(anss) << "\n";
  for (auto ans : anss) cout << ans << "\n";
  return 0;
}
