#include<bits/stdc++.h>
using namespace std;
int main(){
  double N;cin>>N;
  int ans=0;
  vector<int> a(N);
  for(int i=0;i<N;i++)cin>>a.at(i);
  double ave=accumulate(a.begin(),a.end(),0)/N;
  for(int i=0;i<N;i++)
    if(abs(a.at(ans)-ave)>abs(a.at(i)-ave)) ans=i;
  cout<<ans<<endl;
}