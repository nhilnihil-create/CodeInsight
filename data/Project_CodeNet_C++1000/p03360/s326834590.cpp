#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int k; cin >> k;
  int ma = max(a, b);
  ma = max(ma, c);
  int ans = a + b + c - ma;
  for(int i=0; i<k; i++) ma*=2;
  ans += ma;
  cout << ans << endl;
  return 0;
}
