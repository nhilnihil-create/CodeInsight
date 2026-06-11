#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
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
#define inf 2000000000
#define MOD 1000000007
#define N 200005
#define M 1000005
#define LOG 30
#define KOK 32000
#define EPS 0.000000001
using namespace std;

vector<int> a[N];

int main() {
 
	//freopen("input.txt","r",stdin);

	int h,w,n,x,y;

	scanf("%d %d %d",&h,&w,&n);

	int ans=h;

	for(int i=1;i<=n;i++) {

		scanf("%d %d",&x,&y);

		a[y].pb(x);

	}

	int last=1;

	for(int i=1;i<=w;i++) {

		sort(all(a[i]));

		if(sz(a[i])==0) last++;

		for(int j=0;j<sz(a[i]);j++) {

			if(a[i][j]<last) {
			
				if(j==sz(a[i])-1) {

					last++;

					break ;

				}

				continue ;
			
			}

			if(a[i][j]>last) {

				umin(ans,a[i][j]-1);

				last++;

				break ;

			}

			while(j<sz(a[i]) && a[i][j]==last) {

				last++;
				j++;

			}

			if(last>h) break ;

			if(j!=sz(a[i])) {

				umin(ans,a[i][j]-1);
				last++;

				break ;

			}

			last++;

			break ;

		}

		if(last>h) break ;

	}

	printf("%d",ans);

}
