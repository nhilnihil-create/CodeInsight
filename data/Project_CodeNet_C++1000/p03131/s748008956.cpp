#include <bits/stdc++.h>
using namespace std;

int main() {
  long long k,a,b;
  cin>>k>>a>>b;
  long long kotae=0;
  if(b-a<=2){
    cout<<k+1<<endl;
  }else{
    kotae+=max(0LL,(k-a+1)/2)*(b-a)+a;
    if((k-a+1)%2==1)kotae++;
    cout<<kotae<<endl;
  }
  return 0;
}