#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string s[5];
  for(int i=0;i<3;i++){
    cin>>s[i];
  }
  cout<<s[0][0]<<s[1][1]<<s[2][2]<<"\n";
  
  return 0;
}