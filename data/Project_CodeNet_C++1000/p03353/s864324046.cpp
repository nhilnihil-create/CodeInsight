#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(obj) (obj).begin(),(obj).end()
#define debug(x) cerr << #x << ": " << endl
#define rep(i,n) for(int i=0; (i)<(n); ++(i))
#define rrep(i,n) for(int i=(n); (i)>=0; --(i))
#define reps(i,s,n) for(int i=(s); (i)<(n); ++(i))
#define maxi(v) distance(v.begin(), max_element(v.begin(), v.end()))
#define mini(v) distance(v.begin(), min_element(v.begin(), v.end()))
#define maxemt(v) *max_element(v.begin(), v.end())
#define minemt(v) *min_element(v.begin(), v.end())
#define lb(v,x) v[lower_bound(v.begin(), v.end(), x) - v.begin()]
#define ub(v,x) v[upper_bound(v.begin(), v.end(), x) - v.begin()]
template<class T> inline bool print(T& x){ cout << x << endl; return true; }
template<class T> inline bool print_(T& x){ cout << x << " "; return true; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll x, ll y){
  if(y==0) return x;
  else return gcd(y, x%y);
  }
ll lcm(ll x, ll y){
  return x / gcd(x,y) * y;
}
const int INF = 1e9;
const ll llINF = 1LL<<60;
const int MOD = 1e9+7;
const double EPS = 1e-9;
int main(){
  string s; cin >> s;
  int num; cin >> num;
  int n = (int)s.size();
  vector<string> ss(n*5);
  int cnt=0;
  rep(i,5){
    rep(j,n){
      rep(k,i+1){
        if(j+k == n) break;
        ss[cnt].push_back(s[j+k]);
      }
      cnt++;
    }
  }
  sort(all(ss));
  ss.erase(unique(all(ss)), ss.end()); 
  //rep(i,5) cout << ss[i] << endl;
  cout << ss[num-1];
  
  return 0;
}
