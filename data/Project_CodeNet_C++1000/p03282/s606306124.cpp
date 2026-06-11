#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int64_t k;
  cin>>s>>k;
  int r=0;
  char x='1';
  for(int i=0;i<s.size();i++){
    if(s.at(i)!='1'){
      x=s.at(i);
      break;
    }
    r++;
  }
  cout<<(r<k?x:'1')<<endl;
}