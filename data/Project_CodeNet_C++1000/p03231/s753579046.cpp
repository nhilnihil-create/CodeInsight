#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
  if(b==0)return a;
  return gcd(b,a%b);
}
long long lcm(long long a,long long b){
  return a*(b/gcd(a,b));
}
int main(){
  long long a,b;cin>>a>>b;
  string s,t;cin>>s>>t;
  long long c=lcm(a,b);
  long long f=gcd(a,b);
  long long d=0,e=0;
  for(int i=0;i<gcd(a,b);i++){
    if(s.at(d)!=t.at(e)){
      puts("-1");
      return 0;
    }
    d+=a/f;
    e+=b/f;
  }
  cout<<c<<endl;
}