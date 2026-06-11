#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string n;
  cin >> n;

  for (char c : n){
    if (c == '1'){
      cout << 9;
    }else{
      cout << 1;
    }
  }
}
