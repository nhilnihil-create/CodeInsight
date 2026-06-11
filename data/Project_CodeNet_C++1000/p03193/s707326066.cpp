#include <stdlib.h>
#include <iostream>
#include <math.h>
 
using namespace std;
 
int main(){
  int n;
  long h,w;
  cin >> n >> h >> w;
  long m[n][2];
  for(int i=0;i<n;i++){
    cin >> m[i][0] >> m[i][1];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(m[i][0]>=h &&m[i][1]>=w){
      ans++;
    }
  }
  cout << ans << endl;

}