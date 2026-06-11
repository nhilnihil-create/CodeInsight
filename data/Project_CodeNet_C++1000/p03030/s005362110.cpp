#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  pair<pair<string, int>, int> pp[n];
  rep(i, n) {
    cin >> pp[i].first.first >> pp[i].first.second;
    pp[i].first.second *= -1;
    pp[i].second = i + 1;
  }
  sort(pp, pp + n);
  rep(i, n){
    cout << pp[i].second << endl;
  }
  return 0;
}