#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
  int a,b;
  cin >> a >> b;
  cout << max((max(a,b)<<1)-1,a+b);
  return 0;
}
