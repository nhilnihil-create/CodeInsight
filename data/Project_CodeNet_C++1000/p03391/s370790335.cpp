#include <bits/stdc++.h>
using namespace std;

#define maxn 200010
#define INF 1e9
#define int ll
typedef long long ll;

int N,A[maxn],B[maxn];
int total = 0;

int32_t main(){
	cin>>N;
	
	int ans = INF;
	
	for (int i=0;i<N;i++){
		int a,b;
		
		cin>>a>>b;
		total += a;
		
		if (a > b) ans = min(ans,b);
		
	}
	
	if (ans == INF) cout<<0;
	else cout<<total - ans;
}
