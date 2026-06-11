#include "bits/stdc++.h"
#define int long long
#define double long double
#define low lower_bound
#define upp upper_bound
#define mod (int)1e9+7
#define inf (int)1e16
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=n;i>=0;i++)
#define all(vec) vec.begin(),vec.end()
#define cend cout<<endl;
#define P pair<int,int>
#define prique priority_queue<P,vector<P>,greater<P>>
using namespace std;
int a,b;
char ans[100][100];
signed main() {
	cin>>a>>b;
	a--; b--;
	printf("100 100\n");
	rep(i,100) {
		rep(j,100) {
			if(i<50) ans[i][j]='.';
			else ans[i][j]='#';
		}
	}
	rep(i,50) {
		bool end=false;
		for(int j=0;j<100;j+=4) {
			if(b==0) {
				end=true;
				break;
			}
			if(i%2==0) {
				ans[i][j]='#';
			}
			else {
				ans[i][j+2]='#';
			}
			b--;
		}
		if(end) break;
	}
	rep(i,50) {
		bool end=false;
		for(int j=0;j<100;j+=4) {
			if(a==0) {
				end=true;
				break;
			}
			if(i%2==0) {
				ans[99-i][j]='.';
			}
			else {
				ans[99-i][j+2]='.';
			}
			a--;
		}
		if(end) break;
	}
	rep(i,100) {
		rep(j,100) {
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
	/*
	 * #...#...#...
	 * ..#...#...#.
	 * #...#...#...
	 * .###.###.###
	 * ##.###.###.#
	 * .###.###.###
	 */
}
