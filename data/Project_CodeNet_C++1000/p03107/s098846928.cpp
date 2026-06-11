#include <bits/stdc++.h>
using namespace std;

int main(){
  string tumiki;
  cin>>tumiki;
  int count1=0;
  int count2=0;
  for(int i=0;i<tumiki.size();++i){
    if(tumiki.at(i)=='0'){
      count1++;
    }
    else{
      count2++;
    }
  }
  int ans=min(count1,count2);
  cout<<ans*2<<endl;
}
