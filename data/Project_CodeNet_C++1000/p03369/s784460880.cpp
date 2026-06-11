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
  int ans=0;
  ans=700;
  cin>>s;
  for(int i=0;i<3;i++){
    if(s[i]=='o'){
      ans+=100;;
    }
  }
  cout<<ans<<"\n";
      
  return 0;
}