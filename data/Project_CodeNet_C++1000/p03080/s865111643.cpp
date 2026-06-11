/*
ID: skipian1
PROB: 
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF = 2000000000
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define X first
#define Y second

int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int red = 0;
  int blue = 0;
  for (int i = 0; i < n; i++) {
    if (str.at(i) == 'R') red++;
    else blue++;
  }
  if (red > blue) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
