#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int ma = max(a, b);
  ma = max(ma, c);
  int n = 3*ma - a - b - c;
  int ans = n / 2;
  if(n%2==1) ans += 2;
  cout << ans << endl;
  return 0;
}
