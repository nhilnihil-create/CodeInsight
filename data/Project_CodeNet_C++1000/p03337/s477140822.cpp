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
	int a,b;
	cin>>a>>b;
	int ans[3];
	ans[0]=a+b;ans[1]=a-b;ans[2]=a*b;
	sort(ans,ans+3);
	cout<<ans[2];
}