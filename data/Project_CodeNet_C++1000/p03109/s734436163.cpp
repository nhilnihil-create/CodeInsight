#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  if(s[6]>52 || s[5]>48){
    cout<<"TBD"<<"\n";
  }
  else{
    cout<<"Heisei"<<"\n";
  }
  
  return 0;
}