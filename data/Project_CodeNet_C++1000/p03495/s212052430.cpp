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
  ll n,k,a[200010],cnt[200010]={};
  cin>>n>>k;
  rep(i,n){
    cin>>a[i];
    cnt[a[i]]++;
  }

  ll max=0;
  sort(cnt,cnt+200010);

  rep(i,200010){
    if(cnt[i]>0)max++;
  }
  ll ans=0;
  if(max<=k){
    cout<<0<<endl;
    return 0;
  }

  ll tmp=0,tmp2=0;
  while(1){
    if(cnt[tmp]!=0){
      ans+=cnt[tmp];
      tmp2++;
      if(tmp2==max-k){
        break;
      }
    }
    tmp++;
  }
  cout<<ans<<endl;


  return 0;
}
