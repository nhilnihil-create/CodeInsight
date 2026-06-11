#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;

vector <pair<int, int> > v;

int main() {
	int n;
	scanf("%d", &n);
	int sum = n+1 - n%2;
	for (int i=1 ; i<=n ; i++) {
		for (int j=i+1 ; j<=n ; j++) {
			if (i+j != sum) v.pb(mp(i, j));
		}
	}
	printf("%d\n", v.size());
	for (int i=0 ; i<v.size() ; i++) {
		printf("%d %d\n", v[i].x, v[i].y);
	}
	return 0;
}