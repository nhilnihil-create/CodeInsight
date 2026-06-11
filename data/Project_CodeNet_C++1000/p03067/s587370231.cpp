#include<bits/stdc++.h>
using namespace std;
signed main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(a>=c && b<=c || a<=c && b>=c){
    cout<<"Yes\n";
  }else{
    cout<<"No\n";
  }
}
