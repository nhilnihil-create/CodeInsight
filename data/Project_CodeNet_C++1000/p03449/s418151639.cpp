#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> u(n);
  vector<int> d(n);
  int i,j;
  for(i=0;i<n;i++) cin >> u[i];
  for(i=0;i<n;i++) cin >> d[i];
  int max = 0;
  for(i=0;i<n;i++){
    int uu = 0;
    int dd = 0;
    for(j=0;j<=i;j++) uu += u[j];
    for(j=i;j<n;j++) dd += d[j];
    if(max<uu+dd) max = uu+dd;
  }
  cout << max << "\n";
  return 0;
}