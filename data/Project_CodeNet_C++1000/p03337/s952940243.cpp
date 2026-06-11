#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b;
  cin >> a >> b;
  int ans = max(a*b, a-b);
  ans = max(ans, a+b);
  cout << ans << endl;
  return 0;
}
