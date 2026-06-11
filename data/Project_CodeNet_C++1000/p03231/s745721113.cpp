#include <bits/stdc++.h>
using namespace std;
//解説AC
int gcd(int a, int b){
  if (a%b == 0)return(b);
  else return(gcd(b, a%b));
}

int lcm(int a, int b){
  return a * b / gcd(a, b);
}
int main(){
  long long a, b;
  cin >> a >> b;
  long long n=lcm(a,b);
  long long g=gcd(a,b);
  string s,t;
  cin>>s>>t;
  for(int i=0;i<g;i++){
    //cout<<s[i*a/g]<<" "<<t[i*b/g]<<endl;
    if(s[i*a/g]!=t[i*b/g]){
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<n<<endl;
  return 0;
}