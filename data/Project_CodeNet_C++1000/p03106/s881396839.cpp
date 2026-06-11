#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int A,B,K;
  cin>>A>>B>>K;
  int m=min(A,B);
  int ans=0;
  int cnt=0;
  rep(i,m){
      if(A%(m-i)==0&&B%(m-i)==0){
          cnt++;
      }
      if(cnt==K){
          ans=m-i;
          break;
      }
  }
  cout<<ans<<endl;
  
}