#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,x;
  cin>>a>>b>>x;
  x-=a;
   if(b>=x && x>=0){
    cout<<"YES"<<"\n";
  }
  else{
    cout<<"NO"<<"\n";
  }
  return 0;
}