#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  long a[n];
  int i,j;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  long s[n];
  s[0] = a[0];
  for(i=1;i<n;i++){
    s[i]=s[i-1]+a[i];
  }
  long bit[n];
  bit[0]=a[0];
  for(i=1;i<n;i++){
    bit[i]=bit[i-1]^a[i];
  }
  int left,right;
  left=0;
  right=0;
  long ans = 0;
  int chk=0;
  for(left=0;left<n;left++){
    right=max(left,right);
    for(i=right;i<n;i++){
      if(left==0){
        if(s[i]!=bit[i]){
          right = i-1;
          break;
        }
      }else{
        if(s[i]-s[left-1]!=(bit[i]^bit[left-1])){
          right=i-1;
          break;
        }
      }
      if(i==n-1)right=n-1;
    }
    ans += right-left+1;
  }
  cout << ans;
}
