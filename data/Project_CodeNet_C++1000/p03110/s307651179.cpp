#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long double ans = 0;
  for(int i=0; i<N; i++){
    long double x;
    string y;
    cin >> x >> y;
    if(y == "JPY"){
      ans += x;
    }
    else{
      ans += x*380000.0;
    }
  }
  cout << ans << endl;
}
