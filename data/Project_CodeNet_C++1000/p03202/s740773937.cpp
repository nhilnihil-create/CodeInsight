// includes
#include <bits/stdc++.h>
using namespace std;

// macros
#define pb emplace_back
#define mk make_pair
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for(auto itr = (st).rbegin(); itr != (st).rend(); ++itr)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define bit(n) (1LL<<(n))
// functions
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
//  types
using ll = long long int;
using P = pair<int, int>;
using Pli = pair<ll, int>;
using Pil = pair<int, ll>;
using Pll = pair<ll, ll>;
using Pdd = pair<double, double>;
using cd = complex<double>;
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20);}
} fast_io_;

void merge(vector<pair<int, ll>> &v){
  vector<pair<int, ll>> vt;
  for(int i = 0; i < 4; i++){
    if(sz(v)){
      vt.pb(v.back());
      v.pop_back();
    }
  }
  reverse(all(vt));
  for(int i = 1; i < sz(vt); i++){
    if(vt[i].first != vt[i-1].first){
      v.pb(vt[i-1]);
    }else{
      vt[i].second += vt[i-1].second;
    }
  }
  v.pb(vt.back());
}

int main(int argc, char const* argv[])
{
  int n; cin >> n;
  vector<ll> a(n); cin >> a;
  ll ld = 0, rd = n;
  while(rd - ld > 1){
    ll md = (rd + ld) / 2;
    bool ok = true;
    vector<pair<int, ll>> v;
    v.pb(1, a[0]);
    for(int i = 1; i < n; i++){
      if(a[i] > a[i-1]){
        if(v.back().first == 1){
          v.back().second += a[i] - a[i-1];
        }else{
          v.pb(1, a[i] - a[i-1]);
        }
      }else{
        if(a[i] < a[i-1]){
          ll tmp = 0;
          while(sz(v) && tmp < a[i-1] - a[i]){
            auto p = v.back();
            v.pop_back();
            if(tmp + p.second >= a[i-1] - a[i]){
              if(tmp + p.second - a[i-1] + a[i] > 0){
                v.pb(p.first, tmp + p.second - a[i-1] + a[i]);
              }
              break;
            }
            tmp += p.second;
          }
        }
        /*cout << "---";
        rep(j, sz(v)){
          cout << v[j].first << ":" << v[j].second << "\n "[j + 1 != sz(v)];
          }*/
        if(v.back().first != md){
          if(v.back().second == 1)v.back().first++;
          else {
            v.back().second--;
            v.pb(v.back().first + 1, 1);
          }
          merge(v);
        }else{
          if(sz(v) == 1){
            ok = false;
            break;
          }else{
            auto p = v.back();
            v.pop_back();
            if(v.back().second == 1)v.back().first++;
            else {
              v.back().second--;
              v.pb(v.back().first + 1, 1);
            }
            v.pb(1, p.second);
            merge(v);
          }
        }
      }
      /*cout << md << " " << i << "- ";
      rep(j, sz(v)){
        cout << v[j].first << ":" << v[j].second << "\n "[j + 1 != sz(v)];
        }*/
    }
    if(ok)rd = md;
    else ld = md;
  }
  cout << rd << endl;
  return 0;
}
