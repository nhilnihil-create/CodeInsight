#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, k;
  cin >> n >> k;
  int ans;
  if(n%k==0) ans = 0;
  else ans = 1;
  cout << ans << endl;
  return 0;
}
