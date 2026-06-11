#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main() {
  int a,b,q;
  long inf=1e18;
  cin>>a>>b>>q;
  vector<long>s(a+2),t(b+2),x(q);
  s.at(0)=t.at(0)=-inf;
  s.at(a+1)=t.at(b+1)=inf;
  rep(i,a){
    cin>>s.at(i+1);
  }
  rep(i,b){
    cin>>t.at(i+1);
  }
  rep(i,q){
    cin>>x.at(i);
  }
  rep(i,q){
    long ans=inf;
    long d=x.at(i);
    
    int A=lower_bound(s.begin(),s.end(),d)-s.begin();
    
    int B=lower_bound(t.begin(),t.end(),d)-t.begin();
    rep2(i,A-1,A+1){
      rep2(j,B-1,B+1){
        long now=min(abs(s.at(i)-d)+abs(t.at(j)-s.at(i)),abs(t.at(j)-d)+abs(t.at(j)-s.at(i)));
        ans=min(ans,now);
      }
    }
    cout<<ans<<endl;
  }
}