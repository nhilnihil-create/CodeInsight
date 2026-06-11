//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pb push_back
using namespace std;

long double dp[305][305][305];

/*int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll cnt[4]={0,0,0,0};
	ll x;
	for(int i=0;i<n;i++){
		cin>>x;
		cnt[x]++;
	}
	dp[0][0][0]=0;
	for(ll three=0;three<=n;three++){
		for(ll two=0;two<=n;two++){
			for(ll one=0;one<=n;one++){
				ld i=three,j=two,k=one;
				ll zero=n-two-three-one;
				ld zero1=zero,n1=n;
				if(zero<0 || zero==n) continue;
				ld value=1.0;
				if(three>0) value+=(i/n1)*dp[three-1][two+1][one];
				if(two>0) value+=(j/n1)*dp[three][two-1][one+1];
				if(one>0) value+=(k/n1)*dp[three][two][one-1];
				//dp[three][two][one]=(value)/(1-1.0*zero/n);
				dp[three][two][one]=(value*n1)/(i+j+k);
			}
		}
	}
	ld ans=dp[cnt[3]][cnt[2]][cnt[1]];
	cout.precision(20);
	cout<<ans;
}*/

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)x++;
        else if(a[i]==2)y++;
        else z++;
    }
    long double va;
    dp[0][0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                va=1.0;
                if((i+k+j)>n)continue;
                if(!(i) && !(j) && !(k))continue;
                if(i)
                va+=(dp[i-1][j+1][k]*((long double)i/n));
                if(j)
                va+=(dp[i][j-1][k+1]*((long double)j/n));
                if(k)
                va+=(dp[i][j][k-1]*((long double)k/n));
                dp[i][j][k]=((va*n)/((long double)i+j+k));
            }
        }
    }
    cout<<fixed<<setprecision(20)<<dp[z][y][x];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
