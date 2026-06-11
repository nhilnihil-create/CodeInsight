#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string str[3];
  rep(i,3) cin >> str[i];
  cout << str[0][0] << str[1][1] << str[2][2] << endl;
}
