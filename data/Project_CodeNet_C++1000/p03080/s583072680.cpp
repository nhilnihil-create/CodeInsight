#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  string s;
  cin >> N >> s;
  int red = 0;
  for(int i = 0; i < N; i++) {
    if(s[i] == 'R') red++;
  }
  if(red > N - red)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}