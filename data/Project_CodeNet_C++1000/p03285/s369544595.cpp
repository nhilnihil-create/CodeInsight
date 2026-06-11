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
	int n;cin>>n;
	for(int i=0;i<n/4+1;++i){
		for(int j=0;j<n/7+1;++j){
			if(i*4+j*7==n){
				cout<<"Yes";return 0;
			}
		}
	}
	cout<<"No";
}