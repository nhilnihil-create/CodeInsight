#include<bits/stdc++.h>
using namespace std;

int main(void)
{
  vector<int>a(4);
  for(int i=0;i<4;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  if((a[0]*1000+a[1]*100+a[2]*10+a[3])==1479){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}