#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a[3];
  for(int i=0; i<3; i++) cin >> a[i];
  sort(a, a+3);
  int ans=0;
  ans = a[2] - a[1];
  ans += a[1] - a[0];
  cout << ans << endl;
  return 0;
}
