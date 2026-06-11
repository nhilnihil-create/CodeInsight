#include <bits/stdc++.h>
#define int long long
#define INF 100000000000
using namespace std;

/* let a b c be the current bamboo lengths. A,B,C are to be achieved. */
int dfs(int l[], int n, int a, int b, int c, int A, int B, int C, int idx){
	if(idx == n) // finally perform the extension/shortening magic
		return (a&&b&&c)?((abs(A-a)+abs(B-b)+abs(C-c))-30):INF; // subtract 30 cuz intially selecting 3 bamboos doesn't require any cost. hence subtract finally.
	int comp_a = dfs(l, n, a+l[idx], b, c, A, B, C, idx+1) + 10; // use current bamboo in array for compositional magic of a
	int comp_b = dfs(l, n, a, b+l[idx], c, A, B, C, idx+1) + 10; // same but b
	int comp_c = dfs(l, n, a, b, c+l[idx], A, B, C, idx+1) + 10;	// same but c
	int dont_use = dfs(l, n, a, b, c, A, B, C, idx+1); // don't use the current bamboo for any of a or b or c
	return min(min(comp_a, comp_b), min(comp_c, dont_use)); // return minimum of all
}

int32_t main()
{
   int n, A, B, C;
   cin >> n >> A >> B >> C;
   int l[n];
   for(int i=0; i<n; i++)
       cin >> l[i];
    int ans = dfs(l, n, 0, 0, 0, A, B, C, 0);
	cout << ans << endl;
}