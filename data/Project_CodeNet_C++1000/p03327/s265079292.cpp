#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  if(n>=1000){
    cout<<"ABD"<<"\n";
  }
  else{
    cout<<"ABC"<<"\n";
  }
  return 0;
}