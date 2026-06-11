#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

ll solve (string S) {
  int res = 0, i = 0, j = S.size()-1;
  while (i<j) {
    if (S[i]==S[j]) i++, j--;
    else if (S[i]=='x') res++, i++;
    else if (S[j]=='x') res++, j--;
    else return -1;
  }
  return res;
}

int main() {
  string s;
  while (cin >> s) cout << solve(s) << endl;  
}