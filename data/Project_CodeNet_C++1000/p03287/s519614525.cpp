#include <bits/stdc++.h>
using namespace std;


int main() {
long N,M;
cin>>N>>M;
vector<long> a(N);
for(int i=0;i<N;i++){
  cin>>a[i];
  a[i]%=M;
}
long ans=0;
vector<long> r(N);
r[0]=a[0];
if(r[0]==0) ans++;

for(int i=1;i<N;i++){
  r[i]=r[i-1]+a[i];
  r[i]%=M;
  if(r[i]==0) ans++;
}

map<long,long> modm;
for(int i=0;i<N;i++){
modm[r[i]]++;
}

for (auto& x:modm) {
  long n=x.second;
  ans+=n*(n-1)/2;
        }
cout<<ans<<endl;
}
