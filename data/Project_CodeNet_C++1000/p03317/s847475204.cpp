#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, k; 
  cin >> n >> k;
  int ans = 1;
  ans += (n-k)/(k-1);
  if((n-k)%(k-1)!=0) ans++;
  cout << ans << endl;
  return 0;
}
