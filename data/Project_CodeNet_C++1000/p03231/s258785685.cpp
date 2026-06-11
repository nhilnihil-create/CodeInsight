#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
  return b ? gcd(b,a%b) : a;
}

int main(){
  long long n,m;
  cin >> n >> m;
  string s,t;
  cin >> s;
  cin >> t;
  long long g=gcd(n,m);
  long long ans=n/g*m;
  bool ok=true;
  n=n/g;
  m=m/g;
  for(int i=0;i<g;++i){
    if(s[i*n]!=t[i*m]) ok=false;
  }

  if(ok==true){
    cout << ans << endl;
  }else{
    cout << "-1" << endl;
  }
  return 0;

}
