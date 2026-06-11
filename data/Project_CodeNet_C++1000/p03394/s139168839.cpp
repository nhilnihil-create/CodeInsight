#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define pcnt __builtin_popcount
#define show(x) cout<<#x<<" = "<<x<<endl;
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define fi first
#define se second
#define rng(a) (a.begin()),(a.end())
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz(x) (int)(x).size()
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef set<int> si;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll;
typedef set<ll> sl;
typedef __int128_t lll;
typedef pair<lll,lll> plll;
typedef vector<lll> vlll;
template<typename T>string join(vector<T>&v)
{stringstream s;FOR(i,0,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename A, size_t N, typename T>void Fill(A (&array)[N], const T&v)
{fill((T*)array,(T*)(array+N),v);}
lll gcd(lll a,lll b,lll &x,lll &y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll gcd(ll a,ll b){lll x=0,y=0; return gcd(a, b, x, y);}
ll modpow(lll a,lll n,ll m){if(a==0)return a;lll p=1;for(;n>0;n/=2,a=a*a%m)if(n&1)p=p*a%m;return(ll)p;}
void dout(double d){printf("%.12f\n",d);}

const int iinf = 1e9;
const ll linf = 1e18;
const int mod = 1e9+7;
const double pi = acos(-1);
const double eps = 1e-10;

pii m[30];
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  m[0] = mp(14, 16);
  m[1] = mp(15, 16);
  m[2] = mp(14, 18);
  m[3] = mp(15, 18);
  m[4] = mp(16, 18);
  m[5] = mp(15, 20);
  m[6] = mp(16, 20);
  m[7] = mp(16, 21);
  m[8] = mp(18, 20);
  m[9] = mp(18, 21);
  m[10] = mp(18, 22);
  m[11] = mp(20, 21);
  m[12] = mp(20, 22);
  m[13] = mp(21, 22);
  m[14] = mp(20, 24);
  m[15] = mp(21, 24);
  m[16] = mp(22, 24);
  m[17] = mp(22, 25);
  m[18] = mp(22, 26);
  m[19] = mp(24, 25);
  m[20] = mp(24, 26);
  m[21] = mp(25, 26);
  m[22] = mp(25, 27);
  m[23] = mp(26, 27);
  m[24] = mp(26, 28);
  m[25] = mp(27, 28);
  m[26] = mp(12, 14);
  m[27] = mp(12, 15);
  m[28] = mp(12, 16);
  m[29] = mp(14, 15);
  int n;
  cin >> n;
  if(n == 3){
    cout << "2 3 25" << endl;
    return 0;
  }
  ll s = 0;
  FOR(i, 1, 30001){
    if(i%2 && i%3 && i%5) continue;
    cout << i << " ";
    s += i;
    n--;
    if(n == 2){
      pii r = m[(30-s%30)%30];
      i = i/30*30+30;
      cout << i + r.fi << " " << i + r.se << endl;
      return 0;
    }
  }
  return 0;
}
