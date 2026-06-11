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
	int n;
	ll a[10000];
	cin>>n;
	fori(n){cin>>a[i];}
	ll sum=0;
	fori(n){
		int j;
		for(j=0;a[i]%2==0;a[i]/=2,++j);
		sum+=j;
	}
	cout<<sum;
}