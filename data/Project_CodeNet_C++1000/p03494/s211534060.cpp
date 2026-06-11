#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

int gcd(int a, int b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

int lcm(int a, int b) { //最小公倍数
  return a * b / gcd(a, b);
}


int main()
{
  ll n,a[300];
  cin>>n;
  rep(i,n)cin>>a[i];

  ll m=1e15;
  rep(i,n){
    if(a[i]%2==1){
      cout<<0<<endl;
      return 0;
    }else{
      ll tmp=0;
      while(a[i]%2==0){
        a[i]/=2;
        tmp++;
      }
      m=min(tmp,m);
    }
  }
  cout<<m<<endl;

  return 0;
}
