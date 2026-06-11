#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1<<(x))
#define inf 1000000005
#define MOD 1000000007 
#define N 150005
#define M 1000003
#define LOG 20
#define KOK 250
#define EPS 0.0000001
using namespace std;

int n,m,cur,lst;
int last[1<<18];
ii a[1<<18];
vector<int> has[1<<18];

int msb(int val,int& req) {

	for(int i=n-1;i>=0;i--) {

		if((val>>i)&1) return i;

		req|=(1<<i);

	}

}

void dfs(int mask) {

	if(sz(has[mask])==2 || last[mask]==lst) return ;

	has[mask].pb(cur);
	last[mask]=lst;

	for(int i=0;i<n;i++) {

		if((mask>>i)&1) {

			dfs(mask^(1<<i));

		}

	}

}

int main() {

	scanf("%d",&n);

	m=1<<n;

	for(int i=0;i<m;i++) {
	
		scanf("%d",&a[i].st);

		a[i].nd=i^(m-1);
	
	}

	sort(a,a+m,greater<ii>());

	for(int i=0;i<m;i++) {

		cur=a[i].st;
		lst=i+1;

		dfs(a[i].nd);

	}

	for(int i=1;i<m;i++) {

		int req=0;
		int ans=0;

		for(int big=msb(i,req);big>=0;big--) {

			req^=(1<<big);

			if((i>>big)&1) {

				if(sz(has[req])==2) umax(ans,has[req][0]+has[req][1]);

				req^=(1<<big);

			}

		}

		if(sz(has[req])==2) umax(ans,has[req][0]+has[req][1]);

		printf("%d\n",ans);

	}

}