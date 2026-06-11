#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int N,A[200005];
signed main(){
	cin>>N;
	int ok=N,ng=0;
	rep(i,N){
		cin>>A[i];
		if(i&&A[i-1]>=A[i])ng=1;
	}
	while(ok-ng>1){
		int mid=(ok+ng)/2;
		int ans[20];memset(ans,0,sizeof(ans));
		rep(i,min(20ll,A[0]))ans[i]=1;
		bool flag=true;
		REP(i,N){
			if(A[i]>20)for(int j=A[i-1];j<20;j++)ans[j]=1;
			else {
				if(A[i-1]<A[i])for(int j=A[i-1];j<A[i];j++)ans[j]=1;
				else {
					int now=A[i]-1;
					while(now>=0&&ans[now]==mid)now--;
					if(now==-1)flag=false;
					else {
						ans[now]++;
						for(int j=now+1;j<A[i];j++)ans[j]=1;
					}
				}
			}
		}
		if(flag)ok=mid;
		else ng=mid;
	}
	cout<<ok<<endl;
}
