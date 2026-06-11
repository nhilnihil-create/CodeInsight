#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define INF 1e9+7
#define cases int t;cin>>t;while(t--)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define ff first
#define ss second

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	ll n1,k;
	cin>>n1>>k;
	string s;
	cin>>s;
	// ll cnt=0,mx;
	vector<ll>l1,r1,l2,r2;
	ll flag=0,a,b;
	if(s[0]=='0'){
		a=0;
		flag=0;
	}
	else{
		b=0;
		flag=1;
	}
	rep(i,1,n1){
		if(s[i]=='1'&&flag==0){
			flag=1;
			b=i;
			l2.pb(a+1);
			r2.pb(i);
		}
		else if(s[i]=='0'&&flag){
			flag=0;
			a=i;
			l1.pb(b+1);
			r1.pb(i);
		}
	}
	if(flag){
		l1.pb(b+1);
		r1.pb(n1);
	}
	else{
		l2.pb(a+1);
		r2.pb(n1);
	}
	
	if(l2.size()<k)
		k=l2.size();
	ll cnt;
	ll p=0,mx=-INF;
	if(s[0]=='1'){
		if(l2.size()==0){
			cout<<n1;
			return 0;
		}
		rep(i,k-1,l2.size()){
			if(l1.size()>=(i+2)){
				cnt=r1[i+1];
			}
			else{
				cnt=r2[i];
			}
			cnt-=p;
			if(mx<cnt)
				mx=cnt;
			p=r2[i-k+1];
		}
	}
	else{
		if(l2.size()==0){
			cout<<n1;
			return 0;
		}
		rep(i,k-1,l2.size()){
			if(l1.size()>=(i+1)){
				cnt=r1[i];
			}
			else{
				cnt=r2[i];
			}
			// test1(cnt)
			cnt-=p;
			if(mx<cnt)
				mx=cnt;
			p=r2[i-k+1];
		}
	}
	cout<<mx;
	return 0;
}