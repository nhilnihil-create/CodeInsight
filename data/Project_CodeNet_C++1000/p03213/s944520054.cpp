#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  int a[n+1] = {};
  for(int i=2; i<=n; i++){
    int tmp = i;
    for(int j=2; j<=n; j++){
      if(tmp==0) break;
      if(tmp%j==0){
        while(tmp%j==0){
          tmp /= j;
          a[j]++;
        }
      }
    }
  }
  vector<int> ans(80, 0);
  ans[1] = 1;
  for(int i=1; i<=n; i++){
    if(a[i]) for(int j=75; j>=1; j--){
      for(int k=1; k<=a[i]; k++){
        if(j*(k+1)<=75) ans[j*(k+1)] += ans[j];
      }
    }
  }
  cout << ans[75] << endl;
  return 0;
}
