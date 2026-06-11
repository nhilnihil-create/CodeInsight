//each exchange takes two steps
//
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long k,a,b;cin>>k>>a>>b;
  if(b-a<=2){cout<<k+1;return 0;}
  //first reach a;
  long long ret=1;
  long long z = min(k,a-1);
  ret+=z;
  k-=z;
  ret+=(b-a)*(k/2);
  ret+=(k%2);
  cout<<ret;
}