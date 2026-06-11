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
  if(s[0]=='A'){
    cout<<"T"<<"\n";
  }
  else if(s[0]=='T'){
    cout<<"A"<<"\n";
  }
  else if(s[0]=='C'){
    cout<<"G"<<"\n";
  }
  else{
    cout<<"C"<<"\n";
  }
  return 0;
}