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
bool isprime(int num){
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
  int ans[55];
  int p=0;
  for(int i=1;i<=55555;i++){
    if(p==55){
      break;
    }
    if(isprime(i)==true&&i%5==1){
      ans[p]=i;
      p++;
    }      
  }
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}