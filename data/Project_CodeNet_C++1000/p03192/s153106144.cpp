#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,sum=0;
  cin>>n;
  for(int i=0;i<4;i++){
    if(n%10==2) sum++;
    n/=10;
  }
  cout<<sum<<'\n';
  return 0;
}
