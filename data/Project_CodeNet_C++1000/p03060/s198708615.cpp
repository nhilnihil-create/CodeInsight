#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  int bit = 1<<n;
  int a[n], b[n];
  int ans = 0;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];
  for(int i=0; i<bit; i++){
    int tmp = 0;
    for(int j=0; j<n; j++){
      if (i & (1<<j)) tmp += a[j]-b[j];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
