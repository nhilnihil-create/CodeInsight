#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string ans;
  int ab = abs(a-b);
  int bc = abs(b-c);
  int ac = abs(a-c);
  if((ab<=d && bc<=d) || ac<=d) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
  return 0;
}
