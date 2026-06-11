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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(abs(a-c)<=d||(abs(a-b)<=d&&abs(b-c)<=d)){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}