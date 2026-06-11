#include <bits/stdc++.h>
#define endl '\n'
#define N 1000001
#define mod 1e9+7
using namespace std;
typedef long long ll;
ll n;
ll s[4];
double dp[301][301][301];
double pro(ll a,ll b,ll c){
    if(a+b+c==0)return 0.0;
    if(dp[a][b][c]>-0.5)return dp[a][b][c];
    double ks=(double)n/(a+b+c);
    double res=0;
    if(a){
        res+=(pro(a-1,b,c)+ks)*a/(a+b+c);
    }
    if(b){
        res+=(pro(a+1,b-1,c)+ks)*b/(a+b+c);
    }
    if(c){
        res+=(pro(a,b+1,c-1)+ks)*c/(a+b+c);
    }
    return dp[a][b][c]=res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++){
	    ll t;
	    cin>>t;
	    s[t]++;
	}
	for(ll i=0;i<=n;i++){
	    for(ll j=0;j<=n;j++){
	        for(ll k=0;k<=n;k++){
	            dp[i][j][k]=-1;
	        }
	    }
	}
	double res;
	res=pro(s[1],s[2],s[3]);
	printf("%.12f",res);
	return 0;
}
