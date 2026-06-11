#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)

#define n_l '\n'
template <typename T, size_t N> int SIZE(const T (&t)[N]) { return N; } template<typename T> int SIZE(const T &t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)),  __jjj__ = min(x2, SIZE(b) - 1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2 - x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += n_l; return res; } void dbgm() {;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cout << to_string(H) << " | "; dbgm(T...); }
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl


int32_t main() {
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

   int n;
   cin >> n;
   vector <int> hgt(n), bty(n);
   for (auto &i : hgt)
      cin >> i;
   for (auto &i : bty)
      cin >> i;
   if (n <= 1000) {
      int ans = 0;
      set <int> s;
      map <int, int> m;
      m[hgt[0]] = bty[0];
      s.insert(hgt[0]);
      for (int i = 1; i < n; i++) {
         auto it = s.upper_bound(hgt[i]);
         it--;
         if (*it > hgt[i])
            m[hgt[i]] = bty[i];
         else
            m[hgt[i]] = m[*it] + bty[i];
         s.insert(hgt[i]);
         auto ut = s.lower_bound(hgt[i]);
         auto st = ++ut, et = s.end();
         vector <int> temp;
         for (auto at = st; at != s.end(); at++) {
            if (m[*at] <= m[hgt[i]]) {
               temp.push_back(*at);
            }
         }
         for (auto &j : temp) {
            m[j] = 0;
            s.erase(s.find(j));
         }
      }

      for (auto &i : m) {
         ans = max(ans, i.ss);
      }
      cout << ans << '\n';
   } else {
      int ans = 0;
      set <int> s;
      map <int, int> m;
      m[hgt[0]] = bty[0];
      s.insert(hgt[0]);
      for (int i = 1; i < n; i++) {
         auto it = s.upper_bound(hgt[i]);
         it--;
         if (*it > hgt[i])
            m[hgt[i]] = bty[i];
         else
            m[hgt[i]] = m[*it] + bty[i];
         ans = max(ans, m[hgt[i]]);
         s.insert(hgt[i]);
         auto ut = s.lower_bound(hgt[i]);
         auto st = ++ut, et = s.end();
         vector <int> temp;
         for (auto at = st; at != s.end(); at++) {
            if (m[*at] <= m[hgt[i]]) {
               temp.push_back(*at);
            } else {
               break;
            }
         }
         for (auto &j : temp) {
            m[j] = 0;
            s.erase(s.find(j));
         }
      }
      cout << ans << '\n';
   }




   return 0;
}