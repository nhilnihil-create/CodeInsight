#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s;
  cin>>s;
  int num=1000000000;
  int size=s.size()-1;
  for(int i=0;i<size;i++){
    if(s[i+1]!=s[i]){
      num=min(num,max(i+1,size-i));
    }
  }
  cout<<((num==1000000000)?(size+1):(num))<<endl;
  return 0;
}