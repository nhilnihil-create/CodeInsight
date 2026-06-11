#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a + b > c + d) cout << "Left" << "\n";
  else if(a + b == c + d) cout << "Balanced" << "\n";
  else cout << "Right" << "\n";
  return 0;
}
