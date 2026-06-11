#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int r;
  cin>>r;
  if(r<1200){
    cout<<"ABC"<<"\n";
  }
  else if(r<2800){
    cout<<"ARC"<<"\n";
  }
  else{
    cout<<"AGC"<<"\n";
  }
  return 0;
}