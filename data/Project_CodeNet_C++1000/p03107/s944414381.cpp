#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int a=0,b=0,c=0;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='0'){
      a++;
    }
    else if(s.at(i)=='1'){
      b++;
    }
  }
  c=min(a,b);
  cout<<c*2<<endl;
}
