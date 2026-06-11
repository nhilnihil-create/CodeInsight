#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, m;
  cin >> n;
  map<char, int> mp;
  char c;
  rep(i, n){
    cin >> c;
    mp[c]++;
  }
  cout << (mp.size() == 3 ? "Three" : "Four") << endl;
  return 0;
}