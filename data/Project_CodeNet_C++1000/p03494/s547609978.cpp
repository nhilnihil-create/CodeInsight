#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int ans = 100000000;
  for (int i=0;i<N;i++){
  	int a;
    cin >> a;
    int j = 0;
    while (a%2==0){
      a /= 2;
      j++;
    }
    if (ans > j) ans = j;
  }
  cout << ans << endl;
}