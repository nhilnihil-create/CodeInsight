#include<bits/stdc++.h>
#include<map>
#include<set>
using namespace std;
int main () {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string ku = S.substr(0, N);
  string ma = S.substr(N, N);
  map<pair<string, string>, long long>pre;
  set<pair<string, string>>af;
  map<pair<string, string>, long long>aft;
  for (int i_ = 0; i_ < 1 << N; i_ ++) {
    int i = i_;
    string k = "";
    string u = "";
    int si = 0;
    for (int j = 0; j < N; j ++) {
      if (i % 2) k += ku[j];
      else {
        u += ku[j];
        si ++;
      }
      i /= 2;
    }
    string al = "";
    for (int j = si - 1; j >= 0; j --) al += u[j];
    pre[make_pair(k, al)] ++;
  }
  for (int i_ = 0; i_ < 1 << N; i_ ++) {
    int i = i_;
    string k = "";
    string u = "";
    int si = 0;
    for (int j = 0; j < N; j ++) {
      if (i % 2) k += ma[j];
      else {
        u += ma[j];
        si ++;
      }
      i /= 2;
    }
    string al = "";
    for (int j = si - 1; j >= 0; j --) al += u[j];
    aft[make_pair(al, k)] ++;
    af.insert(make_pair(al, k));
  }
  long long ans = 0;
  for (auto x : af) {
    ans += pre[x] * aft[x];
    //cout << x.first << ' ' << x.second << endl;
    //cout << pre[x] << ' ' << aft[x] << endl;
  }
  cout << ans << endl;
}

