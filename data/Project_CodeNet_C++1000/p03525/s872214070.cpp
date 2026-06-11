#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fr front()
#define tp top()
typedef long long int ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <int, pii> pip;
#define iofast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iofile freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
const ll LLINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1);
const int SIZE = 100005;

int N;
int A[SIZE];

int main (){
	
	scanf("%d", &N);
	A[0]=0;
	for(int i=1;i<=N;i++){
		scanf("%d", &A[i]);
	}
	sort(A,A+N+1);
	// for(int i=0;i<=N;i++){
	// 	printf("%d ", A[i]);
	// }
	// printf("\n");
	for(int i=0;i<=N;i++){
		if(i%2==0) A[i]=24-A[i];
		if(A[i]==24) A[i]=0;
		
	}
	// for(int i=0;i<=N;i++){
	// 	printf("%d ", A[i]);
	// }
	// printf("\n");
	sort(A,A+N+1);
	// for(int i=0;i<=N;i++){
	// 	printf("%d ", A[i]);
	// }
	// printf("\n");
	int ans=INF;
	for(int i=1;i<=N;i++){
		ans=min(ans,A[i]-A[i-1]);
	}
	printf("%d\n", ans);
	
	return 0;
}