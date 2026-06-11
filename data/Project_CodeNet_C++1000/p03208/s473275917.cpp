#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	int n,k;
	ll h[alength];
	cin>>n>>k;
	fori(n){cin>>h[i];}
	sort(h,h+n);
	ll ans=INF;
	fori(n-k+1){
		ans=min(h[i+k-1]-h[i],ans);
	}
	cout<<ans;
}