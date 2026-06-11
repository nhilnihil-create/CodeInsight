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
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i+=2){
		int hoge=0;
		for(int j=1;j<=i;++j){
			if(i%j==0){
				++hoge;
			}
		}
		if(hoge==8){
			++ans;
		}
	}
	cout<<ans;
}