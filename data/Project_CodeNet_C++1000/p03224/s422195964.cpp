/* dsingh_24 */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll ,ll>
#define vll          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

#define N  100005
vll a[N];

int main()
{
    ios
   	ll n,i,j;
   	cin>>n;
   	if(n==1){
   		cout<<"Yes\n2\n1 1\n1 1";return 0;
   	}
   	ll cnt=1,lin=4;
   	a[1].pb(1);
   	a[1].pb(2);
   	a[2].pb(2);
   	a[2].pb(3);
   	a[3].pb(3);
   	a[3].pb(1);
   	cnt=4;
   	if(n<3){cout<<"No";return 0;}
   	while(1){
   		//cout<<cnt<<"\n";
   		if(cnt==n+1){
   			cout<<"Yes\n";
   			cout<<lin-1<<"\n";
   			for(i=1;i<lin;i++){
   				cout<<a[i].size()<<" ";
   				for(auto ii:a[i])cout<<ii<<" ";
   					cout<<"\n";
   			}
   			return 0;
   		}
   		ll req=a[1].size(),ptr=1;
   		for(j=cnt;j<=cnt+req;j++){
   			a[lin].pb(j);
   			a[ptr].pb(j);ptr++;
   		}
   		lin++;
   		cnt+=req;
   		if(cnt>n){
   			cout<<"No";return 0;
   		}
   		cnt++;
   	}
    return 0;
}