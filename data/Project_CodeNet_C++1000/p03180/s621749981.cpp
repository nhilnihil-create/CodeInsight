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
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
	for(int mask=0;mask<(1<<n);mask++){
		vector <int> v;
		for(int i=0;i<n;i++) if(mask&(1<<i)) v.pb(i);
		for(int i=0;i<v.size();i++) for(int j=i+1;j<v.size();j++)
			dp[mask]+=a[v[i]][v[j]];
	}
	for(int msk=0;msk<(1<<n);msk++){
		for(int msk2=msk;msk2;msk2=(msk2-1)&msk){
			checkmax(dp[msk],dp[msk^msk2]+dp[msk2]);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}

