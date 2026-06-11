#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n;
  cin >> n;
  int a[2][n];
  for(int i=0; i<2; i++){
    for(int j=0; j<n; j++){
      cin >> a[i][j];
      if(j>0) a[i][j] += a[i][j-1];
    }
  }
  int ma= a[0][0] + a[1][n-1];
  for(int i=1; i<n; i++){
    ma = max(ma, a[0][i] + a[1][n-1] - a[1][i-1]);
  }
  cout << ma << endl;
  return 0;
}
