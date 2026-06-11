#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define INF 1e15
int main()
{
	
ll n,g;cin>>n>>g;
ll f[n+1],c[n+1];
for(ll i=0;i<n;i++)
cin>>f[i]>>c[i];


// we should try every permutation in this problem

vector<ll> perm(n);
iota(perm.begin(), perm.end(), 0);
ll mi=1000000009;

do
{
    ll sum=0;
     ll count=0;
	for(int i=0;i<n;i++)
	{
		ll idx=perm[i];
		ll times=f[idx];
		ll need=g-sum;
		ll p=(idx+1)*100;
		
		ll check=need/p+(need%p>0);/// jine v chaide a bro
		
		if(check<=f[idx])
		{
					count+=check;
					sum+=(check*p);
					sum+=c[idx];
					break;
					

		}
		else if(check>f[idx]){
		count+=f[idx],sum+=(f[idx]*p),sum+=c[idx];}
		
		if(sum>=g)break;
	
	}
	
	
	mi=min(count,mi);
	
}while (next_permutation(perm.begin(), perm.end()));


cout<<mi<<endl;





}