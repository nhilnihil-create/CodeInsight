#include<bits/stdc++.h>
using namespace std;

int value(int n){
  if(n < 0)
    n *= -1;
  return n;
}
int main(void){
  int d, x[3], tmp, cnt = 0;
  bool ans = false;
  for(int i = 0; i < 3; i++)
    cin >> x[i];
  cin >> d;
  tmp = value(x[0] - x[1]);
  if(tmp <= d)
    cnt++;
  tmp = value(x[1] - x[2]);
  if(tmp <= d)
    cnt++;
  tmp = value(x[0] - x[2]);
  if(tmp <= d)
    ans = true;
  if(cnt == 2)
    ans = true;
  if(ans) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
