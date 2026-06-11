#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, x, mi=2000, ans = 0;
  cin >> n >> x;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    if(mi>a) mi = a;
    x -= a;
    ans++;
  }
  ans += x/mi;
  cout << ans << endl;
  return 0;
}
