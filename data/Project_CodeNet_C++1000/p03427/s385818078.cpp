#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string n; cin>>n;
  if(n.size()==1){
    cout<<n[0]-'0'<<endl;
    return 0;
  }
  for(int i=1;i<n.size();i++){
    if(n[i]!='9'){
      cout<<(n.size()-1)*9+(n[0]-'0')-1<<endl;
      return 0;
    }
  }
  cout<<n[0]-'0'+9*(n.size()-1)<<endl;
  
}