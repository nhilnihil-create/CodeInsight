#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)

ll gcd(ll n,ll m){
  if(n>m) return gcd(m,n);
  else if(n==0) return m;
  else return gcd(m-n*(m/n),n);
}

int main(){
  ll t,a,b,c,d,g;
  cin>>t;
  fr(i,t){
    cin>>a>>b>>c>>d;
    if(b>a||b>d){
      cout<<"No"<<endl;
      continue;
    }
    if(c>=b){
      cout<<"Yes"<<endl;
      continue;
    }
    a%=b;
    d%=b;
    if(d==0){
      if(a>c){
        cout<<"No"<<endl;
        continue;
      }
      else{
        cout<<"Yes"<<endl;
        continue;
      }
    }
    g=gcd(b,d);
    if(a%g-g+b>c){
      cout<<"No"<<endl;
      continue;
    }
    else{
      cout<<"Yes"<<endl;
      continue;
    }
  }
}