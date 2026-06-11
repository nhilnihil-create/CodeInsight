/*Arnab's Code
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define vll vector<ll>
#define vii vector<int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define take(a,n) for(ll i=0;i<n;i++)cin>>a[i]
#define takes(a,n,st) for(ll i=st;i<n+st;i++)cin>>a[i]
ll sum(ll a[],ll n,ll s){ for(ll i=0;i<n;i++)s+=a[i]; return s;}
#define mod 1000000009
ll power(ll x, ll y, ll p)  {  
    ll res = 1;  
    x = x % p;   
    if (x == 0) return 0;  
    while (y > 0){  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}
ll a[200017];
void solve(){
	ll n,i,x,tot;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
//		cout<<a[i]<<" ";
		a[i]-=(i+1);
//		cout<<i+1<<" "<<a[i]<<endl;
	}
	sort(a,a+n);
	if(n%2 ==1)
		x=a[n/2];
	else{
		x=(a[n/2]+a[(n/2)-1])/2;
	}
	tot=0;
	for(i=0;i<n;i++){
//		cout<<a[i]<<" "<<tot<<endl;
		tot+=abs(a[i]-x);
	}
	cout<<tot;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll t,T;
//	cin>>T;
	T=1;
	for(t=1;t<=T;t++){
//		cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}