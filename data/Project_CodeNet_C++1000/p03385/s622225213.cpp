//初見でわからなかった

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  char a, b, c;
  cin >> a >> b >> c;

  if (a != b && b != c && c != a) cout << "Yes" << endl;
  else cout << "No" << endl;
}
