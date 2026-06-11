#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  string t;
  
  cin>>s>>t;
  
  string s1=s;
  string t1=t;
  
  reverse(s.begin(),s.end());
  reverse(t.begin(),t.end());
  
  if(s1==t && t1==s){
    cout << "YES" << endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}