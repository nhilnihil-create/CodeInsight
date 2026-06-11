#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  vector<vector<char>> a(3,vector<char>(3));
  rep(i,3)rep(j,3)cin >> a.at(i).at(j);
  cout << a.at(0).at(0) <<a.at(1).at(1)<<a.at(2).at(2)<< endl;
}