#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) { //最小公倍数
  return a * b / gcd(a, b);
}

ll digit_sum(ll a){ //10進桁和
  ll ans=0;
  while(a>0){
    ans+=a%10;
    a/=10;
  }
  return ans;
}



int main()
{
  ll n,t[100010],x[100010],y[100010];
  t[0]=0;
  x[0]=0;
  y[0]=0;
  cin>>n;
  reps(i,n+1)cin>>t[i]>>x[i]>>y[i];
  ll start=0;
  rep(i,n){
    if(t[i+1]-t[i]<abs(x[i+1]-x[i])+abs(y[i+1]-y[i])||(t[i+1]-t[i])%2!=abs(x[i+1]-x[i]+y[i+1]-y[i])%2){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}
