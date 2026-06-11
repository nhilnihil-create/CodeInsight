#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,i,j;
  set<int> z={1};
  cin>>x;
  for(i=2;i*i<=x;i++){
    j=i*i;
    while(j<=x){
      z.insert(j);
      j*=i;
    }
  }
  cout<<*rbegin(z)<<endl;
}