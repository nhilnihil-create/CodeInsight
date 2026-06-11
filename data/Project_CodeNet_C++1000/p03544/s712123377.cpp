#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int64_t a = 2ll,b = 1ll;
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    a += b;
    swap(a,b);
  }
  cout << b << endl;
  return 0;
}
