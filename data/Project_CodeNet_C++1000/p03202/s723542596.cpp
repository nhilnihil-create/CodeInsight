#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

/*
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  vl a(n);
  rep (i, n) {
    cin >> a[i];
  }
  vl num(n);
  num[0] = 0;
  ll ans = 0;
  ll sum = 0;
  rep1 (i, n - 1) {
    if (a[i - 1] > a[i]) {
      ll temp = a[i];
      while (a[i - 1] > temp) {
        num[i]++;
        temp *= 4;
      }
      num[i] += num[i - 1];
      ans += num[i] * 2;
    }
    else {
      ll temp = a[i - 1];
      num[i] = num[i - 1];
      while (4*temp <= a[i]) {
        num[i]--;
        temp *= 4;
      }
      ans += num[i] * 2;
    }
    sum += num[i];
  }
  vl s(n);
  stack<int> st;
  rrep (i, n) {
    int cnt = 1;
    while (!st.empty() && num[st.top()] > num[i]) {
      cnt++;
      st.pop();
    }
    if (st.empty()) {
      s[i] = (n - i)*num[i];
    }
    else {
      s[i] = (st.top() - i) * num[i] + num[st.top()];
    }
    st.push(i);
  }
   DEBUG_VEC(num);
   DEBUG_VEC(s);
   DEBUG(ans);
  ll right = ans, left = 0;
  ll pre = -INF;
  rep (i, n) {
    int cnt = 0;
    ll temp = a[i];
    temp = temp * -2;
    left++;
    while (temp < pre) {
      pre *= 4;
      cnt += 2;
    }
    left += cnt*i;
    if (i == n - 1) {
      right = 0;
    }
    else {
      right = (sum - num[i] - s[i + 1]) * 2;
    }
    ans = min(ans, left + right);
    sum -= num[i];
    pre = a[i] * -2;
  }
  cout << ans << endl;
}
//*/

int main() {
  int n;
  cin >> n;
  vl a(n);
  rep (i, n) {
    cin >> a[i];
  }
  bool flag = true;
  rep1 (i, n - 1) {
    if (a[i - 1] >= a[i]) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << 1 << endl;
    return 0;
  }
  ll ng = 1, ok = 2*n;
  while (ng + 1 < ok) {
    ll x = (ng + ok) / 2;
    vector<pii> v;
    bool flag = true;
    rep1 (i, n - 1) {
      if (a[i] > a[i - 1]) {
        continue;
      }
      int keta = a[i] - 1;
      while (v.size() && v.back().first > keta) {
        v.pop_back();
      }
      while (v.size() && v.back().first == keta && v.back().second == x-1) {
        v.pop_back();
        keta--;
        if (keta < 0) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
      if (v.size() && v.back().first == keta) {
        v.back().second++;
      }
      else {
        v.push_back(pii(keta, 1));
      }
    }
    if (flag) {
      ok = x;
    }
    else {
      ng = x;
    }
  }
  cout << ok << endl;
}
      
