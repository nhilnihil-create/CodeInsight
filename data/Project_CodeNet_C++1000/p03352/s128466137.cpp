#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int64_t x;
  cin>>x;


  int64_t max_wk=0;
  for(int i=2;i*i<=x;i++){
    int64_t wk=i;
    while(wk*i<=x){
      wk*=i;
    }
    max_wk=max(wk,max_wk);
  }

  if(x==1)
    cout<<1<<endl;
  else
    cout<<max_wk<<endl;

	return 0;
}