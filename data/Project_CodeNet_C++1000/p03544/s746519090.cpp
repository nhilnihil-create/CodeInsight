#include <bits/stdc++.h>
using namespace std;
 
int64_t lNum(int n){
    if(n==0){
      return 2;
    }
    else if(n==1){
      return 1;
    }
    else{
    int64_t a=2,b=1,c;
    for(int i=0;i<n-1;i++){
      c=a+b;
      a=b;
      b=c;
    }
    return b;
  }
}

int main() {
  int n;
  int64_t m;
  cin>>n;
  m=lNum(n);
  printf("%lld",m);
}