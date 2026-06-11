#include<bits/stdc++.h>
using namespace std;

int main(){
 
  long long Y,ans;
  string s;
  ans=0;
 cin>>s>>Y;

for(int i=0;i<s.size();i++){
  if(i%Y==0){
  cout<<s[i];
  }
}
  cout<<endl;
    
}
