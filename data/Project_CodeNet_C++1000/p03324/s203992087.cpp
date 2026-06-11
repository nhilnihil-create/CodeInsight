#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int d, n, num;
  cin >> d >> n;
  if(d==0){
    num=n;
    if(n==100)num+=num/100;
  }else if(d==1){
    num=n*100;
    if(n==100)num+=num/100;
  }else{
    num=n*10000;
    if(n==100)num+=num/100;
  }
  cout << num << endl;
  return 0;
}