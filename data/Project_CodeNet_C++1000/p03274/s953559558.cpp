#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define ll long long
#define se second
using namespace std;

int main(){
	// int t;cin>>t;while(t--){
		// ll n;cin>>n;ll s[n+1],c[n+1],f[n+1];
		// for(int i=1;i<=n-1;i++)
		// {
		// 	cin>>c[i]>>s[i]>>f[i];
		// }
	
		// for(int i=1;i<=n-1;i++)
		// {
		// 	ll total=0;
		// 	total+=c[i]+s[i];
		// 	for(int j=i+1;j<=n-1;j++)
		// 	{
		// 		if(total<=s[j])
		// 		total=s[j]+c[j];
		// 		else
		// 		{
		// 			if(total%f[j]==0)
		// 			total=total+c[j];
		// 			else
		// 				total+=(total%f[j])+c[j];
					
		// 		}
				
		// 	}
		// 	cout<<total<<endl;
		// }
		// cout<<"0\n";
		
		
		
		
		ll n,k;cin>>n>>k;
		ll a[n+1];
		vector<ll> pos,neg;
		int f=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0){f++;continue;}
			if(a[i]<0)neg.push_back(a[i]*-1);
			else pos.push_back(a[i]);
			
		}
					ll P[n+1]={0},N[n+1]={0};
		P[0]=0,N[0]=0;
		if(f==1)--k;
		if(k==0){cout<<"0\n";}

		else if(neg.size()==0)
		{
					sort(pos.begin(),pos.end());
					for(int i=0;i<pos.size();i++)
					P[i+1]=P[i]+(pos[i]-P[i]);
					cout<<P[k]<<endl;


		}
		else if(pos.size()==0)
		{
					sort(neg.begin(),neg.end());
					for(int i=0;i<neg.size();i++)
					N[i+1]=N[i]+(neg[i]-N[i]);
					cout<<N[k]<<endl;

		}
		else
		{
		sort(pos.begin(),pos.end());
		sort(neg.begin(),neg.end());
		for(int i=0;i<neg.size();i++)
		N[i+1]=N[i]+(neg[i]-N[i]);
		for(int i=0;i<pos.size();i++)
		P[i+1]=P[i]+(pos[i]-P[i]);
		

			ll mi=10000000009;
			for(int i=0;i<neg.size();i++)
			{
				
			// cout<<k<<"  "<<i+1<<"  "<<N[i+1]<<"  "<<N[i+1]*2+pos[k-(i+1)-1]<<"  "<<pos.size()<<"  "<<mi<<endl;

			if(k-i+1==0){mi=min(mi,N[i+1]);break;}
			if(k-(i+1)>0)
			{
			if(pos.size()>=k-(i+1))
			mi=min(mi,N[i+1]*2+pos[k-(i+1)-1]);
			else continue;
			}
			
			
			}
			
			
			for(int i=0;i<pos.size();i++)
			{
				
			// cout<<k<<"  "<<i+1<<"  "<<P[i+1]<<"  "<<P[i+1]*2+neg[k-(i+1)-1]<<"  "<<neg.size()<<"  "<<mi<<endl;

			if(k-i+1==0){mi=min(mi,P[i+1]);break;}
			if(k-(i+1)>0)
			{
			if(neg.size()>=k-(i+1))
			mi=min(mi,P[i+1]*2+neg[k-(i+1)-1]);
			else continue;
			}
			}
			
			cout<<mi<<endl;
			
			
			
		}
		
		
		
		
		
		
		
		
		
}