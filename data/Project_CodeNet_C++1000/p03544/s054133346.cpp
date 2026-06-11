#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n, f1=2, f2=1, fn;
  cin >> n;
  for (int i = 1; i <= n; ++i){
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    cout << f1;
    return 0;
}
