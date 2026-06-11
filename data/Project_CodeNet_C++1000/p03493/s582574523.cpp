#include <bits/stdc++.h>
using namespace std;

int main() {
  int s1s2s3,ans;
  cin>>s1s2s3;
  ans=s1s2s3/100;
  ans=ans+s1s2s3/10-10*ans;
  ans=ans+s1s2s3%10;
   
  cout<<ans<<endl;
}