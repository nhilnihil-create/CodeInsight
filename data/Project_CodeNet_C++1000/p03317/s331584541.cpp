#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  for(int i;i<n;i++){
    cin>>a.at(i);
  }
  if(((n-1)%(k-1))==0){
    cout<<(n-1)/(k-1)<<endl;
  }
  else{
    cout<<(n-1)/(k-1)+1<<endl;
  }

}