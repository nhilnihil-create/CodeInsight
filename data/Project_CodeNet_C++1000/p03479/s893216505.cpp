#include <bits/stdc++.h>
using namespace std;
int main(){
  long long x,y;
  cin>>x>>y;
  long long sum=x;
  long long count=0;
  while(sum<=y){
    sum*=2;
    count++;
  }
  cout<<count<<endl;
}