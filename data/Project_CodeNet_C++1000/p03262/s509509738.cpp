#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int64_t n,x;
  cin>>n>>x;

  vector<int64_t> a(n+1);


  for(int i=0;i<n;i++){
      cin>>a.at(i);
  }
  a.at(n)=x;
  sort(a.begin(),a.end());


  int64_t gcd_wk;
  if(n==1){
    gcd_wk=a.at(1)-a.at(0);
  }
  else{
    gcd_wk=gcd(a.at(1)-a.at(0),a.at(2)-a.at(1));
    for(int i=2;i<n;i++){
      gcd_wk=gcd(a.at(i+1)-a.at(i),gcd_wk);
    }
  }

  cout<<gcd_wk<<endl;

	return 0;
}