#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, d, x;
  cin >> n >> d >> x;
  int ans = x;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    ans += (d-1)/a + 1;
  }
  cout << ans << endl;
  return 0;
}
