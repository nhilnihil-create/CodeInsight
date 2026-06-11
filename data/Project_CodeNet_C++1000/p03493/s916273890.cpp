#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string s;
  int a=0;
  cin>>s;
  for(int i=0;i<3;i++){
    if(s[i]=='1'){
	a++;
      }
  }
      cout<<a<<"\n";
      
  return 0;
  }