#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n,B,a,b,count=0,sum=0,f=0;cin>>n>>B;
	vector<ll> vc;
	ll mx=-1;
    for(ll i=1;i<=n;i++)
    {
    	cin>>a>>b;
    	vc.push_back(b);
    	mx=max(a,mx);
    }
    sort(vc.begin(),vc.end(),greater<ll>());
    for(ll i=0;i<vc.size();i++)
    {
    	if(vc[i]>mx)++count,sum+=vc[i];
    	else
    	{
    		ll left=B-sum;// 276=46
    		if(left%mx==0)count+=((left/mx));
    		else count+=(left/mx)+1;
    		f=2;
    		break;
    	}
    	if(sum>=B){f=1;break;}
    	
      }
      
      if(f==0)
      {
      		ll left=B-sum;// 276=46
    		if(left%mx==0)count+=((left/mx));
    		else count+=(left/mx)+1;
    		f=2;
    	    cout<<count<<endl;

      }
      else cout<<count<<endl;
}
 
int32_t main() {
ll t=1;
    while (t--)
        solve();
    return 0;
}