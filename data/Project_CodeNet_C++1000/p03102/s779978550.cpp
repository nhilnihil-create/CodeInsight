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
	int n,m,c;
	cin>>n>>m>>c;
	int b[30];
	fori(m){cin>>b[i];}
	int a[30][30];
	fori(n){
		forj(m){
			cin>>a[i][j];
		}
	}
	c*=-1;
	int count=0;
	fori(n){
		int sum=0;
		forj(m){
			sum+=a[i][j]*b[j];
		}
		if(sum>c){
			++count;
		}
	}
	cout<<count;
}