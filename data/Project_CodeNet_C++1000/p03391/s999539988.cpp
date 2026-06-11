#include<iostream>
using namespace std;
#define df 0

int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >> n;
  bool flag=false;
  long int sum=0,MIN_b=1200000000;
  for(int i=0;i<n;i++){
    long int a,b; cin >> a >> b;
    if(a>b){
      flag=true;
      sum+=a;
      if(b<MIN_b)MIN_b=b;
      if(df)cout << sum <<"\n";
    }else{
      sum+=a;
      if(df)cout << sum <<"\n";
    }
  }
  cout << (flag?sum-MIN_b:0);
}

/// confirm df==0 ///
