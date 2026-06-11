#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  string ans;
  if(a+b>=c) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
  return 0;
}
