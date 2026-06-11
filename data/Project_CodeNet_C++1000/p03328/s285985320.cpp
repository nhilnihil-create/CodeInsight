#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;
  long long takasa=0;
  long long takasa2=0;
  for(int i=1;i<=999;i++){
    takasa+=i;
    takasa2=takasa+i+1;
    if(takasa-a==takasa2-b){
      cout<<takasa-a<<endl;
      return 0;
    }
  }
  return 0;
}