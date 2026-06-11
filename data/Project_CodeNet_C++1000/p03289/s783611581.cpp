#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  string s;
  cin>>s;


  bool cond1=false;
  bool cond2=false;
  bool cond3=true;

  if(s.at(0)=='A')
    cond1=true;

  int cnt=0;
  int index=0;
  for(int i=2;i<=s.size()-2;i++){
    if(s.at(i)=='C'){
      cnt++;
      index=i;
    }
  }
  if(cnt==1)
    cond2=true;


  for(int i=0;i<s.size();i++){
    if( (i!=0) && (i!=index) && isupper(s.at(i))){
      cond3=false;
      break;
    }
  }

  if(cond1&&cond2&&cond3)
    cout<<"AC"<<endl;
  else
    cout<<"WA"<<endl;

	return 0;
}