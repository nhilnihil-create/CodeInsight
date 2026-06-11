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
	int n;int a[110],b[110];
	cin>>n;
	fori(n)cin>>a[i];
	fori(n)cin>>b[i];

	ll answer=0;
	fori(n){
		ll score=0;
		for(int j=0;j<=i;++j){score+=a[j];}
		for(int j=i;j<n;++j){score+=b[j];}
		answer=max(answer,score);
	}
	cout<<answer;
}