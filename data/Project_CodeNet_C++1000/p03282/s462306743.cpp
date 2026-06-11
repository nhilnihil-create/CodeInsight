#include <bits/stdc++.h>
using namespace std;


int main(){



  string s;
  cin>>s;
  int k;
  cin>>k;
  

  int ssize=int(s.size());
  

  int flag=-1;
  
  for (int i=0;i<ssize;i++){
    if (s.at(i)!='1'){
      flag=i;
      break;
    }
  }
  
  if (flag==-1){
    cout<<1<<endl;
  }

  else if (k<=flag){
    cout<<1<<endl;
  }
  
  else {
    cout<<s.at(flag)<<endl;
  }
  
  

  
    
    
    

  
}