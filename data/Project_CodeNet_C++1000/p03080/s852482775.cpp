#include <iostream>
#include <string>
using namespace std;

int main(){
  int n;  cin>>n;
  string s; cin>>s;
  int nr=0, nb=0;
  for(int i=0; i<n; i++){
    if(s[i]=='R') nr++;
    if(s[i]=='B') nb++;
  }
  cout<<(nr>nb?"Yes":"No")<<endl;
  return 0;
}