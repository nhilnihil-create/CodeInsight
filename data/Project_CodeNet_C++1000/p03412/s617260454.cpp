/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
inline void Fail(){printf("0");exit(0);}

const int maxn=200005;
const int maxm=30;
int n,ans;
int a[maxn],b[maxn];
vector<int>v[maxm][2];

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n){
		scanf("%d",&b[i]);
		rep(j,29)v[j][b[i]&(1<<j)?1:0].pb(b[i]&((1<<j)-1));
	}
	rep(i,29)rep(j,2)sort(v[i][j].begin(),v[i][j].end());
	rep(j,29){
		int cur=0;
		rep(i,n){
			int ori=cur;
			int now=a[i]&((1<<j)-1);
			if(a[i]&(1<<j)){
				cur+=upper_bound(v[j][0].begin(),v[j][0].end(),(1<<j)-now-1)-v[j][0].begin();
				cur+=v[j][1].size()-(upper_bound(v[j][1].begin(),v[j][1].end(),(1<<j)-now-1)-v[j][1].begin());
			}
			else{
				cur+=upper_bound(v[j][1].begin(),v[j][1].end(),(1<<j)-now-1)-v[j][1].begin();
				cur+=v[j][0].size()-(upper_bound(v[j][0].begin(),v[j][0].end(),(1<<j)-now-1)-v[j][0].begin());
			}
//			cout<<j<<" "<<cur-ori<<endl;
			cur&=1; 
		}
		if(cur&1)ans+=(1<<j);
	}
	printf("%d",ans);
	return 0;
}

/*
Input:
-----------------
Output:
*/