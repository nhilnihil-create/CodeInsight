#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int countR = 0;
  int countB = 0;

  int n;
  string s;
  cin>>n>>s;
 
  for(int i=0;i<n;i++){
    if(s[i]=='R')
    countR++;
    else if(s[i]=='B')
    countB++;
  }  
  if(countR > countB)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;

} 
