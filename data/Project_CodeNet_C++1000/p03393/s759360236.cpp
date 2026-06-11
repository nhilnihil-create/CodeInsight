#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
#define fi first
#define se second
using namespace std;
using lint = long long;
using uint = unsigned int;
using ulint = unsigned long long;
using ldouble = long double;
using pii = pair<int, int>;
using pli = pair<lint, lint>;
using pdd = pair<double, double>;
using pld = pair<ldouble, ldouble>;
using v1i = vector<int>;
using v1li = vector<lint>;
using v2i = vector<vector<int>>;
using v2li = vector<vector<lint>>;
using v3i = vector<vector<vector<int>>>;
using v3li = vector<vector<vector<lint>>>;
using v1b = vector<bool>;
using v2b = vector<vector<bool>>;
using v3b = vector<vector<vector<bool>>>;
using v1c = vector<char>;
using v2c = vector<vector<char>>;
using v3c = vector<vector<vector<char>>>;
constexpr lint mod1 = 1e9+7;
constexpr lint mod2 = 998244353;

int main() {
  string s;
  cin >> s;
  if(s == "zyxwvutsrqponmlkjihgfedcba") cout << -1 << endl;
  else{
    if(s.size() < 26){
      v1b v(26, 1);
      rep(i, s.size()) v[s[i]-'a'] = 0;
      rep(i, 26){
        if(v[i]){
          s += (char)'a'+i;
          break;
        }
      }
      cout << s << endl;
    }
    else{
      string t = "";
      int z = 24;
      while(s[z] > s[z+1]) --z;
      rep(i, z) t += s[i];
      priority_queue<char, vector<char>, greater<char>> pq;
      rep(i, 26-z) pq.push(s[z+i]);
      while(!pq.empty()){
        if(pq.top() > s[z]){
          t += pq.top();
          break;
        }
        else pq.pop();
      }
      cout << t << endl;
    }
  }
  return 0;
}