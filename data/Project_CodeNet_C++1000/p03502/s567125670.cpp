#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int f;
  cin>>n;
  int tmp=n;
  while(tmp>0){
    f+=tmp%10;
    tmp/=10;
  }
  if(n%f==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}