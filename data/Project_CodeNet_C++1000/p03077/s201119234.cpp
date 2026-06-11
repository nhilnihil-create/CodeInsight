#include <bits/stdc++.h>
using namespace std;








int main(){


  long long n,a,b,c,d,e;
  cin>>n>>a>>b>>c>>d>>e;
  
  long long tmp=a;
  tmp=min(tmp,b);
  tmp=min(tmp,c);
  tmp=min(tmp,d);
  tmp=min(tmp,e);
  
  cout<<((n+tmp-1)/tmp)+4<<endl;
  
  

  
    
    
    
  
  

  
  

  

        
}