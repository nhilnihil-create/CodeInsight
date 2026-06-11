#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


int main(){
  ll A,B,Q;cin>>A>>B>>Q;
  vll s(A),t(B),x(Q);
  rep(i,A)cin>>s[i];  sort(all(s));
  rep(i,B)cin>>t[i];  sort(all(t));
  rep(i,Q)cin>>x[i];
  rep(i,Q){
    int a = lower_bound(all(s),x[i]) - s.begin();
    int b = lower_bound(all(t),x[i]) - t.begin();
    ll tmp=1e12;
    //→→　←←　→←　←→
    if(a<A && b<B) tmp = min(tmp,max(s[a],t[b])-x[i]);
    if(a-1>=0 && b-1>=0) tmp = min(tmp,x[i]-min(s[a-1],t[b-1]));
    if(a<A && b-1>=0)tmp = min(tmp,s[a]-x[i]+s[a]-t[b-1]);
    if(b<B && a-1>=0)tmp = min(tmp,t[b]-x[i]+t[b]-s[a-1]);
    if(b<B && a-1>=0)tmp = min(tmp,x[i]-s[a-1]+t[b]-s[a-1]);
    if(a<A && b-1>=0)tmp = min(tmp,x[i]-t[b-1]+s[a]-t[b-1]);
    cout << tmp << endl;
  }
}