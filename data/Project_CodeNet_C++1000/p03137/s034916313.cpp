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

  ll n,m,x[100010],dist[100010];
  cin>>n>>m;
  rep(i,m)cin>>x[i];
  if(m==1){
    cout<<0<<endl;
    return 0;
  }
  sort(x,x+m);
  rep(i,m-1){
    dist[i]=abs(x[i]-x[i+1]);
  }
  sort(dist,dist+m-1);

  // rep(i,m-1)cout<<dist[i]<<endl;
  ll ans=0;
  rep(i,m-n){
    ans+=dist[i];
  }

  cout<<ans<<endl;

  return 0;
}
