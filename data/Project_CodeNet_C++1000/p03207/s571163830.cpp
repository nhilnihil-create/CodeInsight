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
	cin>>n;
	int p[20]={};
	fori(n){cin>>p[i];}
	sort(p,p+n,greater<int>());
	int c=0;
	c+=p[0]/2;
	fori(n-1){
		c+=p[i+1];
	}
	cout<<c;
}