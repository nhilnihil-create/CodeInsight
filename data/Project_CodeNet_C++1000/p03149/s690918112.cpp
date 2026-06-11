#include <bits/stdc++.h>
using namespace std;

int main(){
  set<int> s;
  for(int i=0;i<4;i++){
    int x;
    cin>>x;
    s.insert(x);
  }
  
  if(s.count(1)==1&&s.count(9)==1&&s.count(7)==1&&s.count(4)==1){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}