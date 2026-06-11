#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int d;
  cin >> d;
  cout << "Christmas";
  rep(i,25 - d) cout << " Eve";
  cout << endl;
}
