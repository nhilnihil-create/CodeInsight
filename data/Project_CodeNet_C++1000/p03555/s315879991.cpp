#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string s,p;
  cin>>s>>p;
  if(s[0]==p[2] && s[1]==p[1] && s[2]==p[0]){
    cout<<"YES"<<"\n";
  }
  else{
    cout<<"NO"<<"\n";
  }
  return 0;
}