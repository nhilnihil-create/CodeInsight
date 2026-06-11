#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); ++i)
int main() {
  int n,num,s,a[101]={},p[7]={};
  cin >> n;
  rep(i,n){
      num=i;
      while(num%2==0){
          a[2]++;
          num/=2;
      }
      s=sqrt(num);
      for(int j=3;j<=s;j+=2){
          while(num%j==0){
              a[j]++;
              num/=j;
          }
      }
      if(num!=1){
          a[num]++;
      }
  }
  rep(i,n){
    if(a[i]>=4)
      p[0]++;
    else if(a[i]>=2)
      p[1]++;
    if(a[i]>=14)
      p[2]++;
    else if(a[i]>=4)
      p[3]++;
    if(a[i]>=24)
      p[4]++;
    else if(a[i]>=2)
      p[5]++;
    if(a[i]>=74)
      p[6]++;
  }
  int ans=0;
  ans+=p[0]*(p[0]-1)/2*p[1];
  ans+=p[0]*(p[0]-1)*(p[0]-2)/2;
  ans+=p[2]*p[3];
  ans+=p[2]*(p[2]-1);
  ans+=p[4]*p[5];
  ans+=p[4]*(p[4]-1);
  ans+=p[6];
  cout<<ans;
  return 0;
}