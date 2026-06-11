#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define cool ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define MAX 1000001
#define mod 1000000007
#define pie 3.14159265358979323846
void solve()
{
	int n,i,ans=0;
	cin>>n;
	int h[n];
	for(i=0;i<n;i++)
	cin>>h[i];
	for(i=1;i<n;i++){
		if(h[i-1]>h[i])
		ans+=(h[i-1]-h[i]);
	}
	ans+=h[n-1];
	cout<<ans;
}
int main()
{ 
    cool;
    int t;
    //cin>>t;
    t=1;
    while(t--){
    	solve();
	}
    return 0;
}
