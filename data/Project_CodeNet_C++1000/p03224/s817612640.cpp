#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1<<(x))
#define inf 1005000000
#define MOD 1000000007
#define N 100005
#define M 1000005
#define LOG 20
#define KOK 32000
using namespace std;

int n,tot;
vector<int> s[1005];

int main() {

	//freopen("input.txt","r",stdin);

	scanf("%d",&n);

	n*=2;

	int sq=sqrt(n);

	if(sq*(sq+1)!=n) {

		printf("No");

	}
	else {

		printf("Yes\n");

		printf("%d\n",sq+1);

		for(int i=1;i<=sq+1;i++) {

			for(int j=i+1;j<=sq+1;j++) {

				++tot;

				s[i].pb(tot);
				s[j].pb(tot);

			}

		}

		for(int i=1;i<=sq+1;i++,puts("")) {

			printf("%d ",sq);
	
			for(auto x:s[i]) printf("%d ",x);
	
		}	

	}

}