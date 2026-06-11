#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a[5];
  for(int i=0;i<3;i++){
    cin>>a[i];
  }
  sort(a,a+3);
  if(a[0]==a[1]){
    cout<<a[2]<<"\n";
  }
  else{
    cout<<a[0]<<"\n";
  }
  return 0;
}