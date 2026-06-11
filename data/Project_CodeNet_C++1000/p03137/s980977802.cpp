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
	int n,m;cin>>n>>m;
	int x[alength]={};fori(m){cin>>x[i];}
	if(n>=m){
		cout<<0;return 0;
	}
	sort(x,x+m);
	int d[alength]={};
	fori(m-1){
		d[i]=x[i+1]-x[i];
	}
	sort(d,d+m-1);
	int ans=0;
	fori(m-n){ans+=d[i];}
	cout<<ans;
}