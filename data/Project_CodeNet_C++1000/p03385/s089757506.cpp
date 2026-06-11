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
  int al[26]={};
  cin>>s;
  for(int i=0;i<3;i++){
    if(s[i]=='a'){
      al[1]++;
    }
    else if(s[i]=='b'){
      al[2]++;
    }
     else if(s[i]=='c'){
      al[3]++;
    }
  }
  if((al[1]==1 && al[2]==1) && al[3]==1){
    cout<<"Yes"<<"\n";
  }
  else{
    cout<<"No"<<"\n";
  }
  return 0;
}