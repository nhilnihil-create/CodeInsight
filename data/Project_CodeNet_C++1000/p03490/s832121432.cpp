#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

bool ok1(vector<int> v, int x) {
  if (v.size() == 0) return x == 0;
  map<int,bool> mp[v.size()];
  mp[0][v[0]] = 1;
  for (int i = 1; i < v.size(); i++) {
    int d = v[i];
    for (auto p:mp[i - 1]) {
      mp[i][p.first + d] = 1;
      mp[i][p.first - d] = 1;
    }
  }
  return mp[v.size() - 1][x];
}

bool ok2(vector<int> v, int x) {
  if (v.size() == 0) return x == 0;
  map<int,bool> mp[v.size()];
  mp[0][v[0]] = 1;
  for (int i = 1; i < v.size(); i++) {
    int d = v[i];
    for (auto p:mp[i - 1]) {
      mp[i][p.first + d] = 1;
      mp[i][p.first - d] = 1;
    }
  }
  return mp[v.size() - 1][x] || mp[v.size() - 1][-x];
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int x, y;
  cin >> s >> x >> y;
  int cnt = 0;
  int f = 1;
  vector<int> vec1, vec2;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'F') cnt++;
    else {
      if (f == 1) {
        vec1.push_back(cnt);
        cnt = 0;
        f = 2;
      } else {
        vec2.push_back(cnt);
        cnt = 0;
        f = 1;
      }
    }
  }
  if (f == 1) {
    vec1.push_back(cnt);
  } else {
    vec2.push_back(cnt);
  }
  cout << (ok1(vec1,x) && ok2(vec2,y) ? "Yes":"No") << endl;
  return 0;
}
