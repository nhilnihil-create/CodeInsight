#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,k;
  cin >> a >> b >> k;
  vector<int>ware(100,0);
  for(int i=1;i<=100;i++)
    if(a%i==0&&b%i==0)
      ware.at(i-1)=1;
  int c=0,ans=0;
  for(int i=99;i>=0;i--){
    if(ware.at(i)==1)
      c++;
    if(c==k){
      ans=i+1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}