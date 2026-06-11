#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
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
constexpr int mod = 998244353;
constexpr int inf = 3e18;

int N,X[1005],Y[1005];
void solve(int x,int y){
	for(int i=31;i>=0;i--){
		if(x>0&&y>0){
			cout<<'R';x-=1ll<<i;y-=1ll<<i;
		}else if(x>0){
			cout<<'U';x-=1ll<<i;y+=1ll<<i;
		}else if(y>0){
			cout<<'D';x+=1ll<<i;y-=1ll<<i;
		}else {
			cout<<'L';x+=1ll<<i;y+=1ll<<i;
		}
	}
}
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>N;
	rep(i,N){
		cin>>X[i]>>Y[i];
		if(i&&(X[i]+Y[i]+(1ll<<31))%2!=(X[i-1]+Y[i-1]+(1ll<<31))%2){
			cout<<-1<<endl;return 0;
		}
	}
	cout<<32+((X[0]+Y[0]+(1ll<<31))%2==0)<<endl;
	rep(i,32)cout<<(1ll<<(31ll-i))<<" ";
	if((X[0]+Y[0]+(1ll<<31))%2==0)cout<<1;
	cout<<endl;
	rep(i,N){
		if((X[0]+Y[0]+(1ll<<31))&1){
			solve(X[i]+Y[i],X[i]-Y[i]);
			cout<<endl;
		}else {
			solve(X[i]+Y[i]+1,X[i]-Y[i]+1);
			cout<<'L'<<endl;
		}
	}
}
