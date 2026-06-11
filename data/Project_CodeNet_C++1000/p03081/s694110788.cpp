#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll EXA = 1000000000000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int check(int n, int k, string s, const vector<pair<char, char>> &p) {
  for(int i=0;i<(int)(p.size());++i) {
    int next = (p[i].second == 'L' ? -1 : 1);
    if(s[k] == p[i].first) {
      k += next;
    }
    if(k == 0 || k == n+1) break;
  }
  return k;
}



int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);
  
  int n, q; cin >> n >> q;
  string s; cin >> s;
  s.push_back('*');
  reverse(s.begin(), s.end());
  s.push_back('*');
  reverse(s.begin(), s.end());
  vector<pair<char, char>> p(q);
  for(int i=0;i<q;++i) {
    cin >> p[i].first >> p[i].second;
  }

  int ansl = 0, ansr = 0;

  int l = 0, r = n+2;
  while(r - l > 1) {
    int mid = (l + r) / 2;
    if(check(n, mid, s, p) == 0) {
      l = mid;
    } else {
      r = mid;
    }
  }
  ansl = l;

  l = -1; r = n+1;
  while(r - l > 1) {
    int mid = (l + r + 1) / 2;
    if(check(n, mid, s, p) == n+1) {
      r = mid;
    } else {
      l = mid;
    }
  }
  ansr = r;
  // cout << ansl << ":" << ansr << endl;

  if(ansr > ansl) cout << ansr - ansl - 1 << endl;
  else cout << 0 << endl;
}
