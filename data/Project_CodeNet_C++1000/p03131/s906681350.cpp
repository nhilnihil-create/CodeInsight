#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

long long k, a, b;

int main(){
  cin >> k >> a >> b;
  if(a >= b - 2 || a > k){
    cout << k + 1 << endl;
  }else{
    long long rest = k - a + 1;
    cout << a + ((rest / 2) * (b - a))  + rest % 2<< endl;
  }
  return 0;
}
