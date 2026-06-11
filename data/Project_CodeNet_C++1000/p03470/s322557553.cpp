#include<bits/stdc++.h>
using namespace std;
int main(){
  int z,x,i;
  set<int> y;
  cin>>z;
  for(i=0;i<z;i++){
    cin>>x;
    y.insert(x);
  }
  cout<<y.size()<<endl;
}