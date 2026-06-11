#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int64_t n;
  cin>>n;

 
  int64_t max_wk=0;
  for(int64_t i=1;i*i<=n;i++){
      max_wk=max(i*i,max_wk);
  }

  cout<<max_wk<<endl;

	return 0;
}