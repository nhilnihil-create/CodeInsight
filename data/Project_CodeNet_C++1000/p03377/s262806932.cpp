#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b, x;
  cin >> a >> b >> x;
  string ans;
  if(a<=x && x<=a+b) ans = "YES";
  else ans = "NO";
  cout << ans << endl;
  return 0;
}
