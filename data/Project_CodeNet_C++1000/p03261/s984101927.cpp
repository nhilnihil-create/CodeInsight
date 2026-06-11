#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  char a;
  map<string,int> m;
  for(int i=0;i<n;++i){ 
    string s;
    cin >>s;
    ++m[s];
    if(m[s]>1){
      cout<<"No"<<endl ;
      return 0;
    }
    if(i!=0){
    if(s[0]==a);
    else { 
      cout <<"No"<<endl;
      return 0;
    }
    }
    a=s[s.size()-1];
    
  }
  cout <<"Yes"<<endl ;
}