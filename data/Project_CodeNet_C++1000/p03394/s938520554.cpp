#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n==3){
    cout<<2<<' '<<3<<' '<<25<<endl;
    return 0;
  }
  cout<<2<<' '<<4<<' '<<3<<' '<<9;
  int k=4;
  for(int i=1;i*6+4<=30000&&k<=n-2;i++,k+=2)
    cout<<' '<<i*6+2<<' '<<i*6+4;
  for(int i=1;i*12+9<=30000&&k<=n-2;i++,k+=2)
    cout<<' '<<i*12+3<<' '<<i*12+9;
  for(int i=1;i*6<=30000&&k<n;i++,k++)
    cout<<' '<<i*6;
  cout<<endl;
}