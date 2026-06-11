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
  ll n,x,m[110],sum=0;
  cin>>n>>x;
  rep(i,n){
    cin>>m[i];
    sum+=m[i];
  }
  sort(m,m+n);
  if(x-sum<0){
    cout<<0<<endl;
    return 0;
  }
  cout<<n+(x-sum)/m[0]<<endl;
  return 0;
}
