#include <bits/stdc++.h>
using namespace std;
//#define che
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MK make_pair
#define PB push_back
#define fi first
#define se second

typedef long long LL;
typedef pair<int, int> PII;
const int N=1e5+10 ;

int a[1000][1000];
int main(){
	#ifdef che
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int n; cin>>n;
	for (int m=1; m*(m-1)/2 <=n; ++m)
		if ( m*(m-1)/2 ==n ){
			puts("Yes");
			printf("%d\n", m);
			for (int i=1, cnt=0; i<=m; ++i){
				for (int j=i+1; j<=m; ++j)
					a[i][j] = a[j][i]=++cnt;
				
				printf("%d ", m-1);
				for (int j=1; j<=m; ++j)	if ( a[i][j] ) printf("%d ", a[i][j]);
				puts("");
			}
			return 0;
		}
	puts("No");	
	return 0;
}