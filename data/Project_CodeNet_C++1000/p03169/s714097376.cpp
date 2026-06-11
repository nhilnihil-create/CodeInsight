#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll v[]={0,0,0,0};
double dp[301][301][301];


double countExpectedThrows(ll a1,ll a2,ll a3){
	if(a1==0 && a2==0 && a3==0)
		return 0;
	if(dp[a1][a2][a3]>=0){
		return dp[a1][a2][a3];
	}	
	double ans=n;
	if(a1)
		ans+=a1*countExpectedThrows(a1-1,a2,a3);
	if(a2)
		ans+=a2*countExpectedThrows(a1+1,a2-1,a3);
	if(a3)
		ans+=a3*countExpectedThrows(a1,a2+1,a3-1);
	ans/=(a1+a2+a3);
	dp[a1][a2][a3]=ans;
	return ans;			
}

int main(){
 cin>>n;
 memset(dp,-1,sizeof (dp));
 for(ll i=0;i<n;i++){
 	ll d;
 	cin>>d;
 	v[d]++;
 }
 cout<<fixed<<setprecision(21)<<countExpectedThrows(v[1],v[2],v[3])<<endl;
 return 0;
}