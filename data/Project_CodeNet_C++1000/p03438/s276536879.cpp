#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,a[10005],b[10005];
  ll asum=0,bsum=0,m;
  
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  for (i=0;i<n;i++) cin >> b[i];
  
  for (i=0;i<n;i++) asum+=a[i];
  for (i=0;i<n;i++) bsum+=b[i];
  
  m=bsum-asum;
  
  if (m<0){
    cout << "No" << endl;
    return 0;
  }
  
  if (m==0){
    for (i=0;i<n;i++){
      if (a[i]!=b[i]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  
  ll ao=0,bo=0;
  for (i=0;i<n;i++){
    if (a[i]==b[i]) continue;
    if (a[i]>b[i]){
      bo+=a[i]-b[i];
    }else{
      if ((b[i]-a[i])%2==0){
        ao+=(b[i]-a[i])/2;
      }else{
        ao+=(b[i]-a[i]+1)/2;
        bo++;
      }
    }
  }
  
  if (ao<=m && bo<=m && (m-ao)*2==m-bo){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return 0;
}