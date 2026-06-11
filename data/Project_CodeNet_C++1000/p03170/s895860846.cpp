#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

ll pow(ll a, ll b, ll m)
{
    ll  ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int n;
int a[101];
int ans[100005]={0};

int solve(int k){
    if(ans[k]){
        return ans[k];
    }
    for(int i=0;i<n;i++){
        if(k>=a[i]){
        if(solve(k-a[i])==2){
            ans[k]=1;
            return ans[k];
        }
      }
    }
   ans[k]=2;
   return ans[k];
}

int main()
{
	IOS;
	int t=1; //cin>>t;
	while(t--){
	    int k; cin>>n>>k;
	    for(int i=0;i<n;i++){
	       cin>>a[i];
	   }
	   ans[0]=2;
	   if(solve(k)==1){
	    cout<<"First";   
	   }
	   else{
	       cout<<"Second";
	   }
	    cout<<endl;
	}  
}