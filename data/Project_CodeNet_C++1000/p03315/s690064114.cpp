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
  cin>>s;
  for(int i=0;i<4;i++){
    if(s[i]=='+'){
      ans++;
    }
    else{
      ans--;
    }
  }
  cout<<ans<<"\n";
  return 0;
}