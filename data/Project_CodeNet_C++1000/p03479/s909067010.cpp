#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int x,y;
  int cnt=0;
  cin>>x>>y;
  for(long long int i=x;i<=y;){
    i*=2;
    cnt++;
  }
  cout<<cnt;

}
