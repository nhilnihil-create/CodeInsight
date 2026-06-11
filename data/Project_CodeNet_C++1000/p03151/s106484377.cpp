#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int n;
  cin >> n;
  int i;
  ll c=0,d=0;
  vector<ll> a(n),b(n);
  for(i=0;i<n;i++){
    cin >> a[i];
    c+=a[i];
  }
  for(i=0;i<n;i++){
    cin >> b[i];
    d+=b[i];
  }
  if(c<d){
    cout << -1 << endl;
    return 0;
  }
  ll ans=0,sum=0;
  vector<ll> x;
  for(i=0;i<n;i++){
    if(a[i]>=b[i]){
      x.push_back(a[i]-b[i]);
    }
    else{
      sum+=b[i]-a[i],ans++;
    }
  }
  sort(x.begin(),x.end(),greater<ll>());
  for(i=0;i<x.size();i++){
    if(sum<=0){
      break;
    }
    sum-=x[i];
    ans++;
    if(sum<=0){
      break;
    }
  }
  cout << ans << endl;
}