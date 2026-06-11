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

  ll s;
  cin>>s;

  ll ans=1;
  if(s==1||s==2||s==4){
    cout<<4<<endl;
    return 0;
  }


  while(s!=4){
    ans++;
    if(s%2==0){
      s=s/2;
    }else{
      s=3*s+1;
    }
  }


  cout<<ans+3<<endl;
  return 0;
}
