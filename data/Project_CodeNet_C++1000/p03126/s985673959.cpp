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
	int n,m;
	cin>>n>>m;
	int map[30]={};
	fori(n){
		int k;
		cin>>k;
		forj(k){
			int hoge;
			cin>>hoge;
			++map[hoge-1];
		}
	}

	int c=0;
	fori(m){
		if(map[i]==n){
			++c;
		}
	}
	cout<<c;
}