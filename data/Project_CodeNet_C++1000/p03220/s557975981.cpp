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
	double n,t,a;
	cin>>n>>t>>a;
	double h[1100]={};
	fori(n){cin>>h[i];}

	double score=INF;int ans=0;
	fori(n){
		double s=fabs(a-(t-h[i]*0.006));
		if(s<score){
			score=s;
			ans=i;
		}
	}
	cout<<ans+1;
}