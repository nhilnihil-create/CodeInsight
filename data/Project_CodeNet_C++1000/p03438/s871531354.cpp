#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,a[10005],b[10005];
  ll asum=0,bsum=0,k;
  
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  for (i=0;i<n;i++) cin >> b[i];
  
  for (i=0;i<n;i++) asum+=a[i];
  for (i=0;i<n;i++) bsum+=b[i];
  
  k=bsum-asum;
  
  if (k<0){
    cout << "No" << endl;
    return 0;
  }
  
  if (k==0){
    for (i=0;i<n;i++){
      if (a[i]!=b[i]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  
  ll ra=0,rb=0;
  for (i=0;i<n;i++){
    if (a[i]==b[i]) continue;
    if (a[i]>b[i]){
      rb+=a[i]-b[i];
    }else{
      if ((b[i]-a[i])%2==0){
        ra+=(b[i]-a[i])/2;
      }else{
        ra+=(b[i]-a[i]+1)/2;
        rb++;
      }
    }
  }
  
  if (ra<=k && rb<=k && (k-ra)*2==k-rb){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return 0;
}