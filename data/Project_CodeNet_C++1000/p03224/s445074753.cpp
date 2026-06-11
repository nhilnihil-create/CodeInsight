#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define M 1000000007LL
typedef pair<int,int> ii;
typedef vector<int> vi;

int main() {
	int n;cin >> n;
	map <int,int> poss;
	for (int i=1; i<=1000; i++) {
		poss[(i*(i+1))/2] = i;
	}
	if (poss.count(n)) {
		printf("Yes\n");
		int r = poss[n];
		printf("%d\n", r+1);
		vi unused, duplicate[r+1];
		for (int i=1; i<=n; i++) {
			unused.push_back(i);
		}
		for (int i=0; i<=r; i++) {
			printf("%d ",r);
			for (int k=0; k<i; k++) {
				int v = duplicate[k].back();
				duplicate[k].pop_back();
				printf("%d ", v);
			}
			for (int j=i; j<r; j++) {
				int v = unused.back();
				unused.pop_back();
				duplicate[i].push_back(v);
				printf("%d ", v);
			}
			printf("\n");
		}
	}
	else {
		printf("No\n");
	}
	return 0;
}