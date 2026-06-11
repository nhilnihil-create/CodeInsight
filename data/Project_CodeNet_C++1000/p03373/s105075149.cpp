#include <bits/stdc++.h>
using namespace std;
#define MAX 2000000000;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  int ans = MAX;
  int num = max(x, y);
  for (int i = 0; i <= num; i++){
    int a_num = max(x - i, 0);
    int b_num = max(y - i, 0);
    int p = 2 * c * i + a * a_num + b * b_num;
    if (ans > p) ans = p;
  }
  cout << ans << endl;
}