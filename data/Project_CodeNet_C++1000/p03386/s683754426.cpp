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
  int a,b,c;
  cin >> a >> b >> c;
  if(a+2*c-2>=b){
    for(int i = a;i<b+1;i++){
      cout << i << endl;
    }
  }
  else {for(int i = a;i<a+c;i++){
    cout << i << endl;
  }
  for(int i = b - c + 1;i<=b;i++){
    cout << i << endl;
  }
       }
}