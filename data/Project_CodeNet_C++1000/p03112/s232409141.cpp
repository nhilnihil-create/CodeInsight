#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
const LL INF=1000000000000;

int main(){
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<LL> s(A), t(B), x(Q);
  rep(i,A) cin >> s[i];
  rep(i,B) cin >> t[i];
  rep(i,Q) cin >> x[i];
  rep(i,Q){
    LL X=x[i];
    int s_num=lower_bound(s.begin(),s.end(),X)-s.begin()-1;
    int t_num=lower_bound(t.begin(),t.end(),X)-t.begin()-1;
    LL ans=INF;
    if(s_num>=0&&t_num>=0) ans=min(ans,max(X-s[s_num],X-t[t_num]));
    if(s_num+1<A&&t_num+1<B) ans=min(ans,max(s[s_num+1]-X,t[t_num+1]-X));
    if(s_num>=0&&t_num+1<B) ans=min(ans,(X-s[s_num])*2+t[t_num+1]-X);
    if(s_num+1<A&&t_num>=0) ans=min(ans,(X-t[t_num])*2+s[s_num+1]-X);
    if(s_num+1<A&&t_num>=0) ans=min(ans,(s[s_num+1]-X)*2+X-t[t_num]);
    if(s_num>=0&&t_num+1<B) ans=min(ans,(t[t_num+1]-X)*2+X-s[s_num]);
    cout << ans << endl;
  }

  return 0;
}
