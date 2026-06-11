#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int a[2],k,c[101] = {};
  cin >> a[0] >> a[1] >> k;
  sort(a,a + 2,greater<int>());
  for (int i = 1; i <= a[0]; i++){
    if (a[0] % i == 0 && a[1] % i == 0){
      c[i] = i;
    }
  }
  sort(c,c+101,greater<int>());
  cout << c[k-1] << '\n';
  return 0;
}