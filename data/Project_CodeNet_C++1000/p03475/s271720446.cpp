#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define ll long long
#define se second
using namespace std;

int main(){
		ll n;cin>>n;ll s[n+1],c[n+1],f[n+1];
		for(int i=1;i<=n-1;i++)
		cin>>c[i]>>s[i]>>f[i];
		
	
		for(int i=1;i<=n-1;i++)
		{
			ll total=c[i]+s[i];
			for(int j=i+1;j<=n-1;j++)
			{
				if(total<=s[j])
				total=s[j];
				else if(total%f[j]==0);
				else
				total+=f[j]-(total%f[j]);
				
				total+=c[j];
			}
			cout<<total<<endl;
		}
		cout<<0<<endl;
		
		
		
		
}