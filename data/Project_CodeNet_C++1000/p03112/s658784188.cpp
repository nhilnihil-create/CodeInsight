#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll a,b,q;
  cin >> a >> b >> q;
  vector<ll>s(a),t(b),x(q);
  for(int i=0; i<a; i++) cin >> s[i];
  for(int i=0; i<b; i++) cin >> t[i];
  for(int i=0; i<q; i++) cin >> x[i];
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  
  for(int i=0; i<q; i++){
    ll Iter1 = lower_bound(s.begin(),s.end(),x[i])-s.begin();
    ll Iter2 = lower_bound(t.begin(),t.end(),x[i])-t.begin();
    
    double ans;
    ans = pow(pow(t[Iter2] - s[Iter1],2),0.5) + pow(pow(s[Iter1] - x[i],2),0.5);
    ans = min(ans,pow(pow(t[Iter2] - s[Iter1],2),0.5) + pow(pow(t[Iter2] - x[i],2),0.5));
    if(Iter1 >0 && Iter2>0) ans = min(ans,pow(pow(t[Iter2-1] - s[Iter1-1],2),0.5) + pow(pow(t[Iter2-1] - x[i],2),0.5));
    if(Iter1 >0 && Iter2>0) ans = min(ans,pow(pow(t[Iter2-1] - s[Iter1-1],2),0.5) + pow(pow(s[Iter1-1] - x[i],2),0.5));
    if(Iter1 >0) ans = min(ans,pow(pow(t[Iter2] - s[Iter1-1],2),0.5) + pow(pow(s[Iter1-1] - x[i],2),0.5));
    if(Iter1 >0) ans = min(ans,pow(pow(t[Iter2] - s[Iter1-1],2),0.5) + pow(pow(t[Iter2] - x[i],2),0.5));
    if(Iter2 >0) ans = min(ans,pow(pow(t[Iter2-1] - s[Iter1],2),0.5) + pow(pow(t[Iter2-1] - x[i],2),0.5));
    if(Iter2 >0) ans = min(ans,pow(pow(t[Iter2-1] - s[Iter1],2),0.5) + pow(pow(s[Iter1] - x[i],2),0.5));
    ll Ans = ans;
    cout << Ans << endl;
  }
  
}
  
