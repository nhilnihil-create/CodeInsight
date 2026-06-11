#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;cin>>n;
  vector<ll> a(n);
  rep(i, n)cin>>a[i];

  if(a[0]!=0) {cout<<-1;return 0;}

  ll pre = a[0];
  ll result=0;
  map<ll, ll>m;
  m[pre]++;
  for(ll i=1; i<n; i++){
    if(a[i]-pre>1){cout<<-1;return 0;}
    if(a[i]<pre){
      result+=pre;
      m.clear();
      m[a[i]]++;
    }else{
      m[a[i]]++;
      if(m[a[i]]>1)result += a[i];
    }
    pre=a[i];
//cout<<result<<' '<<pre<<endl;
  }

//  for(auto p:m) cout<<p.first<<' '<<p.second<<endl;

  result+=pre;
  cout<<result;

  return 0;
}