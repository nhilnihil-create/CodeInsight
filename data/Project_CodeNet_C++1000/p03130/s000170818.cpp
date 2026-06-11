#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
  int i,a,b,k[6]={},s=0;
  for (i=0;i<3;i++){
    cin >> a >> b;
    k[a]++;
    k[b]++;
  }
  for (i=1;i<=4;i++){
    if (k[i]==1) s++;
    else if (k[i]!=2) break;
  }
  if (i!=5 || s!=2) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}