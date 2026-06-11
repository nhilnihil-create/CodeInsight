#include <bits/stdc++.h>
using namespace std;


int main() {
long N;
cin>>N;
vector<long> x(N+1);
for(int i=0;i<N+1;i++) cin>>x[i];
long X=x[0];
if(N==1){
  cout<<abs(x[1]-x[0])<<endl;
  return 0;
}
sort(x.begin(),x.end());
long ans=gcd(x[1]-x[0],x[2]-x[1]);
for(int i=0;i<N-2;i++){
  long tmp=gcd(x[i+1]-x[i],x[i+2]-x[1]);
  ans = gcd(ans,tmp);
}
cout<<ans<<endl;
}
