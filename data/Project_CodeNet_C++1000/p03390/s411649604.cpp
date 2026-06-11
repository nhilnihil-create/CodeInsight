#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

signed main() {
  int q;
  cin>>q;
  int a,b,t,p1,q1,p2,q2,ans=0,o=0;
  long double k;
  for(int i=0;i<q;i++){
    ans=0;
    cin>>a>>b;
    k=a*b;
    k=sqrt(k);
  t=floorl(k)+1;
    if(t==a)p1=t+1;
    else p1=t;
    if((a*b)%p1!=0)q1=(a*b)/p1;
    else q1= (a*b)/p1 -1;
    if(q1<b)ans+=q1;
    else  ans+=q1-1;
    if(t==b)q2=t+1;
    else q2=t;
    if((a*b)%q2!=0)p2=(a*b)/q2;
    else p2=(a*b)/q2 -1;
    if(p2<a)ans+=p2;
    else ans+=p2-1;
    if((t-1)*(t-1)==a*b)t--;
    if(t>b&&q1<b)q1++;
    if(t>a&&p2<a)p2++;
    ans+=max(o,min(t-q1-1,t-p2-1));
  cout<<ans<<endl;
  //cerr<<p1<<' '<<q1<<' '<<p2<<' '<<q2<<' '<<t;
  }





  return 0;
}
