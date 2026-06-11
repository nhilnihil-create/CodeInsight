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
	int a,b,k;
	cin>>a>>b>>k;

	int c=0;
	int m=min(a,b);
	for(int i=m;i>0;--i){
		if(a%i==0&&b%i==0){
			++c;
			if(k==c){
				cout<<i;
				return 0;
			}
		}
	}
}