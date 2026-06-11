#include <bits/stdc++.h>
using namespace std;

long kaijo(long n){
  long ret=1;
  for(int i=1;i<=n;i++){
    ret*=i;
  }
  return ret;
}

long com(long n,long r){
  long ans=kaijo(n)/kaijo(r)/kaijo(n-r);
  return ans;
}

int main(){
  int N;

  cin>>N;
  vector<long> a(100);

if(N<=9){
  cout<<0<<endl;
  return 0;
}

for(int i=2;i<=N;i++){
  int m=i;
  for(int j=2;j<=sqrt(i);j++){
    while(m%j==0){
      a[j]++;
      m/=j;
    }
  }
  if(m>1) a[m]++;
}
for(int i=1;i<=N;i++){
//cout<<a[i]<<endl;
}
int f4=0,f2=0,f74=0,f24=0,f14=0;
for(int i=0;i<=N;i++){
  if(a[i]>=74) f74++;
  if(a[i]>=24) f24++;
  if(a[i]>=14) f14++;
  if(a[i]>=4) f4++;
  if(a[i]<4&&a[i]>=2) f2++;
}


long ans=0;

// 1*75
ans+=f74;

// 3*25
ans+=f24*(f4+f2-1);

// 5*15
ans+= f14*(f4-1);

// 3*5*5
if(f4>=3) ans+= f4*com(f4-1,2);
ans+= f2*com(f4,2);


cout<<ans<<endl;


}
