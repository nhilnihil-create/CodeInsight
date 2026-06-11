#include <iostream>
#include <string>
using namespace std;

int main(void){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  
  for(int i=0;i<n;i++){
    if(i==k-1)s[i]+=32;
    
    cout<<s[i];
  }
  return 0;
  
}