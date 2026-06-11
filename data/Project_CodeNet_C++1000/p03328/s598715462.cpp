#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;
  int b;
  cin >> a >> b;
  int ans = (b-a+1)*(b-a)/2-b;
  cout << ans << endl;
}