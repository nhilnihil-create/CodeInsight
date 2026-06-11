#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string a;
  cin>>a;
  for(int i=0;i<3;i++){
    if(a[i]=='1'){
      a[i]='9';
    }
    else{
      a[i]='1';
    }
  }
  cout<<a<<"\n";
  
  return 0;
}