#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;

template<class T> inline void checkmin(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,const T &b){if(b>a) a=b;}

const int inf=1e9+10;
const int maxn=17;

ll dp[1<<maxn],a[maxn][maxn]; 
int n;

int main(){
	for(int i=0;i<(1<<maxn);i++) dp[i]=0ll;
	cin>>n;
	for(int i=0;i<n;i++) a[i][i]=0ll;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
	for(int mask=0;mask<(1<<n);mask++){
		vector <int> v;
		for(int i=0;i<n;i++) if(mask&(1<<i)) v.pb(i);
		for(int i=0;i<v.size();i++) for(int j=i+1;j<v.size();j++)
			dp[mask]+=a[v[i]][v[j]];
	}
//	for(int mask=0;mask<(1<<n);mask++) cout<<dp[mask]<<" "; cout<<endl;
	for(int mask=0;mask<(1<<n);mask++) dp[mask]=max(dp[mask],0ll);
//	for(int mask=0;mask<(1<<n);mask++) cout<<dp[mask]<<" "; cout<<endl;
//	cout<<dp[5]<<" "<<dp[2]<<endl;
	for(int msk=0;msk<(1<<n);msk++){
		int x=-1;
		for(int i=0;i<n;i++) if(msk&(1<<i)){
			x=i; break;
		}
		if(x==-1) continue;
		int msk2=((1<<n)-1)^msk^(1<<x),msk3=0,flag=0;
		for(int i=n-1;i>=0;i--){
			if(!(msk2&(1<<i))) flag=1;
		//	cout<<(msk&(1<<i))<<" "<<flag<<endl;
			if(flag&&(!(msk2&(1<<i)))) msk3|=(1<<i);
		}
	//	cout<<msk2<<" "<<msk3<<endl;
		for(int msk4=msk3;msk4;msk4=(msk4-1)&msk3){
			int msk5=msk4|(1<<x);
			dp[msk]=max(dp[msk5]+dp[msk^msk5],dp[msk]);	
		//	cout<<msk<<" "<<dp[msk]<<" "<<dp[msk5]+dp[msk^msk5]<<endl;
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}

