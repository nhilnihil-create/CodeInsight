#include<iostream>
using namespace std;
int main(){
  int n,a,b,c,l[10],m,i,j,k;
  cin >> n >> a >> b >> c;
  for(i=0;i<n;i++){
    cin >> l[i];
  }
  int ans=2000000000;
  for(i=1;i<(1<<n);i++){
    for(j=1;j<(1<<n);j++){
      for(k=1;k<(1<<n);k++){
        if((i&j)!=0 || (k&j)!=0 || (i&k)!=0){
          continue;
        }
        int sum1=0,sum=0,x=0;
        for(m=0;m<n;m++){
          if(i&(1<<m)){
            sum+=10;
            sum1+=l[m];
            x=1;
          }
        }
        if(x==1){
          sum-=10;
        }
        sum+=abs(a-sum1);
        sum1=0,x=0;
        for(m=0;m<n;m++){
          if(j&(1<<m)){
            sum+=10;
            sum1+=l[m];
            x=1;
          }
        }
        if(x==1){
          sum-=10;
        }
        sum+=abs(b-sum1);
        sum1=0,x=0;
        for(m=0;m<n;m++){
          if(k&(1<<m)){
            sum+=10;
            sum1+=l[m];
            x=1;
          }
        }
        if(x==1){
          sum-=10;
        }
        sum+=abs(c-sum1);
        if(ans>sum){
          ans=sum;
        }
      }
    }
  }
  cout << ans << endl;
}