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
typedef vector<pii> vpii;
typedef set<int> si;
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}

int  N;
ll D[100010];
int n[100010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  rrep(i,N) cin >> D[i];

  vi ind(N);
  vi par(N+1);
  rep(i,N) ind[i] = i+1;
  sort(&ind[0], &ind[N], [](int i1, int i2) {
    return D[i1] > D[i2];
  });
  rep(i,N-1) {
    int ii = ind[i];
    ++n[ii];
    ll Dj = D[ii] + n[ii] * 2 - N;
    srep(j,i+1,N+1) {
      int ij = ind[j];
      if (D[ij] == Dj) {
        par[ii] = ij;
        n[ij] += n[ii];
        break;
      }
    }
    if (par[ii]==0) {
      cout << "-1\n";
      return 0;
    }
  }
  vpii ans;
  v(ll) s(N+1);
  rep(i,N-1) {
    int ii = ind[i];
    s[par[ii]] += s[ii] + n[ii];
    ans.pb(pii(ii, par[ii]));
  }
  if (s[ind[N-1]] != D[ind[N-1]]) {
    cout << "-1\n";
  } else {
    for (auto e : ans) {
      cout << e.fi << " " << e.se << "\n";
    }
  }
  return 0;
}
