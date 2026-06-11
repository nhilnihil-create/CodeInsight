#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int n,h,w;
  cin >> n >> h >> w;
  
  vector<vector<int>>ab(n,vector<int>(2,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<2;j++){
      cin >> ab[i][j];
    }
  }
  
  int ans = 0;
  
  for(int i=0;i<n;i++){
    if(ab[i][0] >= h && ab[i][1] >= w) ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}
