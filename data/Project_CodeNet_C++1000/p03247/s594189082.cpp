#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define rrep(i,n) for(int i=1; i<=(n); ++i)
#define drep(i,n) for(int i=(n)-1; i>=0; --i)
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

int N;
int X[1010];
int Y[1010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  int b0;
  rep(i,N) {
    cin >> X[i] >> Y[i];
    int b = (X[i] + Y[i]) % 2;
    b = (b+2)%2;
    if (i == 0) {
      b0 = b;
    } else if (b != b0) {
      cout << "-1\n";
      return 0;
    }
  }

  int D = 31;
  vi d;
  rep(i,D) d.pb(1<<i);
  if (!b0) d.pb(1);

  cout << sz(d) << '\n';
  cout << d << '\n';

  rep(i,N) {
    string ans = "";
    int P = X[i] + Y[i];
    int M = X[i] - Y[i];
    P += (1<<D)-1;
    M += (1<<D)-1;
    rep(j,D){
      int p = ((1<<(j+1))&P);
      int m = ((1<<(j+1))&M);
      char c;
      if (p)
        if (m) c = 'R';
        else c = 'U';
      else
        if (m) c = 'D';
        else c = 'L';
      ans.pb(c);
    }
    if (!b0) ans.pb('R');
    cout << ans << '\n';
    //debug
    /*/
    int d_x = 0;
    int d_y = 0;
    rep (k,sz(ans)) {
      switch (ans[k]) {
        case 'R':
        d_x += d[k];
        break;
        case 'L':
        d_x -= d[k];
        break;
        case 'U':
        d_y += d[k];
        break;
        case 'D':
        d_y -= d[k];
        break;
      }
    }
    cout << "deb " << d_x << " " << d_y << "\n";
    //*/
  }
  return 0;
}
