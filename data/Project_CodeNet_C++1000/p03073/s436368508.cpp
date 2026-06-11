#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
int main(){
  string s;
  cin>>s;
  int c1=0,c2=0;
  REP(i,s.size()){
    if(i%2==0){
	  if(s[i]=='0')c2++;
      else c1++;
    }else{
      if(s[i]=='0')c1++;
      else c2++;
    }
  }
  cout<<min(c1,c2)<<endl;
}