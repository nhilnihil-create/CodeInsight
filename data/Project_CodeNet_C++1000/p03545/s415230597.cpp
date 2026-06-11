#include<bits/stdc++.h>
using namespace std;

int main(){
  int s,i,j,k,cnt=0;
  cin >> s;
  int a=s/1000,b=s/100-a*10,c=s/10-b*10-a*100,d=s-c*10-b*100-a*1000;
  
  vector<char> op={'+','-'};
  int s1,s2,s3;
  for(i=0;i<2;i++){
    if(cnt>=1){
      break;
    }
    s1=0;
    if(i==0){
      s1=a+b;
    }
    else{
      s1=a-b;
    }
    for(j=0;j<2;j++){
      if(cnt>=1){
        break;
      }
      s2=s1;
      if(j==0){
        s2 +=c;
      }
      else{
        s2 -=c;
      }
      for(k=0;k<2;k++){
        s3=s2;
        if(k==0){
          s3 +=d;
        }
        else{
          s3 -=d;
        }
        if(s3==7){
          vector<int> vec={i,j,k};
          cout << a << op[i] << b << op[j] << c << op[k] << d << '=' << 7 <<endl;
          cnt++;
          break;
          
        }
        else{
          continue;
          
        }
      }
    }
  }
  
  
}
