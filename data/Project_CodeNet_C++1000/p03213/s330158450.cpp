#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}
ll mpower(ll a,ll b,ll c){
  int z;
  if(b==0){
    z=1;
    z%=c;
    return z;
  }
  if(b==1){
    z=a;
    z%=c;
    return z;
  }
  else{
    return (((mpower(a,b/2,c))*(mpower(a,b/2,c))%c)*mpower(a,b%2,c)%c);
  }
}
bool IsPrime(int num){
  if(num<2) return false;
  else if(num==2) return true;
  else if(num%2==0) return false;
  double sqrtNum=sqrt(num);
  for(int i=3;i<=sqrtNum;i+=2){
    if(num%i==0){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin>>n;
  int vec[25];
  int vecb[25];
  int p=0;
  for(int i=1;i<101;i++){
    if(IsPrime(i)==true){
      vec[p]=i;
      p++;
    }
  }
  for(int i=0;i<25;i++){
    p=n;
    vecb[i]=0;
    while(p>=vec[i]){
      vecb[i]+=p/vec[i];
      p/=vec[i];
    }
  }
  int ans=0;
  for(int i=0;i<25;i++){
    if(vecb[i]>=74){
      ans++;
    }
  }
  for(int i=0;i<25;i++){
    for(int j=0;j<25;j++){
      if(i==j){
        continue;
      }
      if(vecb[j]>=2&&vecb[i]>=24){
        ans++;
      }
      if(vecb[j]>=4&&vecb[i]>=14){
        ans++;
      }
    }
  }
  for(int i=0;i<25;i++){
    for(int j=0;j<24;j++){
      for(int k=j+1;k<25;k++){
        if(i==j||j==k||k==i){
          continue;
        }
        if(vecb[i]>=2&&vecb[j]>=4&&vecb[k]>=4){
          ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}