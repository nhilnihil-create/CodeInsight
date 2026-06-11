#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> v1,v2;
ll n;
int solve(int k){
  ll md=(1<<(k+1));
  vector<ll> a,b;
  for(int i=0;i<n;i++) a.push_back(v1[i]%md);
  for(int i=0;i<n;i++) b.push_back(v2[i]%md);
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll t=(1<<k);
  ll res=0;
  for(int i=0;i<n;i++) {
    ll pos1=lower_bound(b.begin(),b.end(),t-a[i])-b.begin();
    ll pos2=lower_bound(b.begin(),b.end(),t*2-a[i])-b.begin();
    ll pos3=lower_bound(b.begin(),b.end(),t*3-a[i])-b.begin();
    ll pos4=lower_bound(b.begin(),b.end(),t*4-a[i])-b.begin();
    res+=(pos2-pos1)+(pos4-pos3);
    res%=2;
  }
  return res;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    v1.push_back(a);
  }
  for(int i=0;i<n;i++){
    ll b;
    cin>>b;
    v2.push_back(b);
  }
  ll ans=0;
  for(int i=0;i<30;i++){
    if(solve(i)==1) ans+=(1<<i);
  }
  cout<<ans<<endl;
}
