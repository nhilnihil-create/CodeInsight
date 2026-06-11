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
	int n,ta;
	cin>>n>>ta;
	int c[110],t[110];
	fori(n){cin>>c[i]>>t[i];}
	
	int ans=INF;
	bool f=true;
	fori(n){
		if(t[i]>ta){
			continue;
		}
		f=false;
		ans=min(c[i],ans);
	}
	if(f){
		cout<<"TLE";return 0;
	}
	cout<<ans;
}