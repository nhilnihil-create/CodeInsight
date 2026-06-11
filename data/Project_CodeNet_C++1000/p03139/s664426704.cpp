#include<bits/stdc++.h>
using namespace std;
signed main(){
  int a,b,c;
  cin>>a>>b>>c;
  cout<<min(b,c);
  if(c+b-a<0){
    cout<<" 0";
  }else{
    cout<<" "<<(c+b)-a;
  }
  cout<<"\n";
}
