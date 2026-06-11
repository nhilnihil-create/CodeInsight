#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  auto s = [](int n){
    int sum = 0;
    while(n != 0){
      sum += n % 10;
      n /= 10;
    }
    return sum;
  };
  int sum = s(n);
  if (n % sum == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}