#include <bits/stdc++.h>
using namespace std;
 


int main() {
  int X,Y;
  cin>>X>>Y;
  
  
  if(X%Y==0)
    cout<<-1<<endl;
  else if(Y%X==0)
    cout<<X<<endl;
  else
    cout<<X<<endl;
  
  return 0;
}