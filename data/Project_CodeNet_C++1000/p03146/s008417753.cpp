#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,fx[100000];
  cin >> a;
  fx[0] = a;
  for(int i = 1;i<100000;i++){
    if(a%2==0) a/=2;
    else a = 3*a+1;
    for(int j = i-1;j>=0;j--){
      if(fx[j]==a){
        cout << i+1;
        return 0;
      }
      fx[i] = a;
    }
  }
}
