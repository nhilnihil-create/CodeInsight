#include <iostream>
using namespace std;
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int i,j;
  int cnt = 0;
  for(i=1;i<=n;i++){
    int x;
    if(i==10000){
      if(a==1) cnt += i;
    }
    else if(i>=1000){
      x = (i/1000+(i%1000)/100+(i%100)/10+i%10);
      if(a<=x&&x<=b) cnt += i;
    }
    else if(i>=100){
      x = (i/100+(i%100)/10+i%10);
      if(a<=x&&x<=b) cnt += i;
    }
    else if(i>=10){
      x = (i/10+i%10);
      if(a<=x&&x<=b) cnt += i;
    }
    else{
      x = i;
      if(a<=x&&x<=b) cnt += i;
    }
  }
  cout << cnt << "\n";
  return 0;
}