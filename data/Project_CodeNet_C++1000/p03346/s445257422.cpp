#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define dbg(n) cout<<#n<<' '<<n<<endl;
int power(ll x,ll y){ 
	ll res = 1;	
	while(y>0){ 
		if(y & 1) 
			res = (res*x)%mod; 
		y=y>>1;
		x=(x*x)%mod;
	} 
	return res; 
}

int main(){ 
	int t;
	cin>>t;
	int a[t+1];
	int n[200001];
	for(int i=1;i<=t;i++){
	cin>>a[i];
	n[a[i]]=i;
	}
	int count,ma=0;
	if(t==1)
	ma=1;
	for(int i=2;i<=t;i++)
{
	count=1;
	while(n[i]>n[i-1]&&i<=t){
		count++;
		i++;
		}
		if(count>ma)
		ma=count;
	}	
	cout<<t-ma<<endl;
}

