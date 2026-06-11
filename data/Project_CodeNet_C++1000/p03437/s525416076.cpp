#include <bits/stdc++.h>
using namespace std;
 
int main() {

  int X,Y,k;
  cin>>X>>Y;
  
  
  if(X%Y==0){
    cout<<-1<<endl;
	return 0;
  }
  
  for(k=1;k<Y;k++){
    if((k*X)%Y!=0){
      cout<<k*X<<endl;
    	return 0;
    }
  }
    cout<<-1<<endl;
	return 0;
}
  