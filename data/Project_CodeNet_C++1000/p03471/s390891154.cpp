#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, y;
  cin >> n >> y;
  rep(i, 2001){
    rep(j, 2001 - i){
      if(i * 10000 + j * 5000 + (n - i - j) * 1000 == y && (n - i - j) > -1){
        cout << i << " " << j << " " << (n - i - j) << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
        

  return 0;
}