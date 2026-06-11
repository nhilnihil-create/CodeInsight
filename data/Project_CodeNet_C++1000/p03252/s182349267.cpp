#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979323846;

int main() {
  string S, T;
  cin >> S >> T;
  map<char, int> dictS, dictT; // 文字列に登場する英小文字と登場回数
  for (int i=0; i<S.size(); i++) {
    if (dictS.count(S[i])) dictS[S[i]]++;
    else dictS[S[i]] = 1;
  }
  for (int i=0; i<T.size(); i++) {
    if (dictT.count(T[i])) dictT[T[i]]++;
    else dictT[T[i]] = 1;
  }
  vector<int> memoS, memoT; // mapのvalueのみ取り出した配列
  for (auto p: dictS) {
    auto value = p.second;
    memoS.push_back(value);
  }
  for (auto p: dictT) {
    auto value = p.second;
    memoT.push_back(value);
  }
  sort(memoS.begin(), memoS.end());
  sort(memoT.begin(), memoT.end());
  if (memoS==memoT) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}