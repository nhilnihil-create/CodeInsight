#include<iostream>
using namespace std;
int main(){
  int n,k,i=1,m=1;
  double ans=0,P=1;
  cin >> n >> k;
  for(i=1;i<=n;i++){
    P=(double)1/n;
    for(m=i;m<k;){
      P=P/2;
      m=m*2;
    }
    ans=ans+P;
  }
  printf("%.10lf",ans);
  return 0;
}
