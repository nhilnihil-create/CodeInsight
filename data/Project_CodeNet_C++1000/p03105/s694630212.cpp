#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c;
  cin>>a>>b>>c;
  if(b/a>=c){
    cout<<c<<"\n";
  }
  else{
    cout<<b/a<<"\n";
  }
  return 0;
}