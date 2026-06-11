#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;
#define MOD 1000000007LL

int main(){
  ll A, B, Q;
  cin >> A >> B >> Q;
  vll s(A), t(B), x(Q);
  for(int i = 0; i < A; i++){
    cin >> s.at(i);
  }
  for(int i = 0; i < B; i++){
    cin >> t.at(i);
  }
  vll ans(0);
  for(int i = 0; i < Q; i++){
    ll x;
    cin >> x;
    ll s1 = INF, s2 = INF, t1 = INF, t2 = INF;

    auto ites = lower_bound(ALL(s), x);
    if(ites != s.end()) s2 = *ites - x;
    if(ites != s.begin()){
      ites--;
      s1 = x - *ites;
    }

    auto itet = lower_bound(ALL(t), x);
    if(itet != t.end()) t2 = *itet - x;
    if(itet != t.begin()){
      itet--;
      t1 = x - *itet;
    }
    ll result = INF;
    chmin(result, max(t2, s2));
    chmin(result, max(t1, s1));
    chmin(result, 2*t1 + s2);
    chmin(result, t1 + 2*s2);
    chmin(result, 2*s1 + t2);
    chmin(result, s1 + 2*t2);
    ans.push_back(result);
  }
  for(auto x: ans) cout << x << endl;
}