#include <bits/stdc++.h>
using namespace std;

int main() {
  long a,b,q,sm,sp,tm,tp;
  cin >> a >> b >> q;
  vector<long> s(a);
  vector<long> t(b);
  vector<long> x(q);
  vector<long> ans(q);
  set<long> ss,ts;
  for(long i=0;i<a;i++) cin >> s[i];
  for(long i=0;i<b;i++) cin >> t[i];
  for(long i=0;i<q;i++) cin >> x[i];

  for(long i=0;i<a;i++) ss.insert(s[i]);
  for(long i=0;i<b;i++) ts.insert(t[i]);
  for(long i=0;i<q;i++) {
    sm=99999999999999,sp=99999999999999,tm=99999999999999,tp=99999999999999;
    auto itr1=ss.lower_bound(x[i]);
    auto itr2=ts.lower_bound(x[i]);
    if(itr1!=ss.end()) sp=*itr1;
    if(itr1!=ss.begin()) {
      itr1--;
      sm=*itr1;
    }
    if(itr2!=ts.end()) tp=*itr2;
    if(itr2!=ts.begin()) {
      itr2--;
      tm=*itr2;
    }
    sm-=x[i],sp-=x[i],tm-=x[i],tp-=x[i];
    sm=labs(sm),sp=labs(sp),tm=labs(tm),tp=labs(tp);
    ans[i]=max(sm,tm);
    ans[i]=min(ans[i],max(sp,tp));
    ans[i]=min(ans[i],sm*2+tp);
    ans[i]=min(ans[i],sp*2+tm);
    ans[i]=min(ans[i],sm+tp*2);
    ans[i]=min(ans[i],sp+tm*2);
    cout << ans[i] << endl;
  }
}