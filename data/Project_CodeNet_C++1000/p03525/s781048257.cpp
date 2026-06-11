#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}



int main()
{
	int n;
	cin>>n;
	vector<int> d(n+1,0);
	repi(i,1,n+1)cin>>d[i];
	rep(i,n+1)d[i]=min(d[i],(24-d[i])%24);

	sort(all(d));
	vector<int> used(24,0);
	used[0]=1;

	int parity=-1;
	repi(i,1,n+1){
		if(parity<0)used[d[i]]++;
		else used[(24-d[i])%24]++;
		parity*=-1;
	}

	int ans=24;
	int prev=0;
	repi(i,1,24){
		if(used[i]>1){
			ans=0;
			break;
		}
		if(used[i]==1){
			ans=min(ans,i-prev);
			prev=i;
		}
	}

	if(prev==0||used[0]>1)ans=0;

	cout<<ans<<endl;

	return 0;
}