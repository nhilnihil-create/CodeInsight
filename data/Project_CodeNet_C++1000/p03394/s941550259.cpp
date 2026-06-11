
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  ll n;
  cin>>n;

  if(n<6){
    if(n==3)cout<<"2 5 63"<<endl;
    if(n==4)cout<<"2 5 20 63"<<endl;
    if(n==5)cout<<"2 5 20 30 63"<<endl;
    return 0;
  }
  
  vector<ll> ans;

  ll sum=0;
  ll k=0;
  ll x[4]={2,3,4,6};
  for(int i=0;i<n;i++){
    k=i/4;
    ll t=k*6+x[i%4];
    sum+=t;
    ans.pb(t);
  }

  for(int i=0;i<n;i++){
    if(sum%6==2&&ans[i]==8){
	 ll tmp;
	 for(int i=1;i<=6;i++){
	   if((ans[n-1]+i)%6==0)tmp=ans[n-1]+i;
	 }
	 ans[i]=tmp;
	 continue;
    }
    if(sum%6==3&&ans[i]==9){
	 ll tmp;
	 for(int i=1;i<=6;i++){
	   if((ans[n-1]+i)%6==0)tmp=ans[n-1]+i;
	 }
	 ans[i]=tmp;
	 continue;
    }
    if(sum%6==5&&ans[i]==9){
	 ll tmp;
	 for(int i=1;i<=6;i++){
	   if((ans[n-1]+i)%6==4)tmp=ans[n-1]+i;
	 }
	 ans[i]=tmp;
	 continue;
    }
    //cout<<ans[i];
  }

  ll ma=0;
  for(int i=0;i<n;i++){
    if(i)cout<<" ";
    cout<<ans[i];
    ma=max(ma,ans[i]);
  }
  cout<<endl;
  // dbg(ma);
  return 0;
}
