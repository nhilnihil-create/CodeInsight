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
	int n,m,x,y;
	cin>>n>>m>>x>>y;--x;--y;
	int xa[100]={},ya[100]={};
	fori(n){cin>>xa[i];--xa[i];}
	fori(m){cin>>ya[i];--ya[i];}
	sort(xa,xa+n,greater<int>());
	sort(ya,ya+m);
	for(int z=x+1;z<=y;++z){
		if(z>xa[0]&&z<=ya[0]){
			cout<<"No War";
			return 0;
		}
	}
	cout<<"War";
}