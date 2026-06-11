#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int a=s[0]-'0',b=s[1]-'0',c=s[2]-'0';
  int d=s[3]-'0';
  for(int i=0;i<8;i++){
    int sum=0;
    sum=sum+a;
    if(i&(1<<0)){    
      sum=sum+b;
    }
    else{
      sum=sum-b;
    }
    if(i&(1<<1)){    
      sum=sum+c;
    }
    else{
      sum=sum-c;
    }
    if(i&(1<<2)){    
      sum=sum+d;
    }
    else{
      sum=sum-d;
    }
    if(sum==7){
      cout << a;
      if(i&(1<<0)){
        cout << '+';
      }
      else{
        cout << '-';
      }
      cout << b;
      if(i&(1<<1)){
        cout << '+';
      }
      else{
        cout << '-';
      }
      cout << c;
      if(i&(1<<2)){
        cout << '+';
      }
      else{
        cout << '-';
      }
      cout << d << "=7" << endl;
      break;
    }
  }
}