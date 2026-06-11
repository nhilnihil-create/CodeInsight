#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int count=0;
  while(1){
    if(n<3)break;
    n-=3;
    count++;
  }
  printf("%d\n",count);
  return 0;
}