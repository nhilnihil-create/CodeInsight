#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

int n, a, b;	

int main() {
	scanf ("%d%d%d", &n, &a, &b);
	printf (((b - a - 1) & 1) ? "Alice\n" : "Borys\n");	
	return 0;
}
