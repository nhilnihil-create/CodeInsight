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
	int t[5];
	fori(5){cin>>t[i];}
	vector<int> a={0,1,2,3,4};
	int ans=INF;
	do{
		int time=0;
		fori(5){
			if(time%10!=0){
				time+=(10-(time%10));
			}
			time+=t[a[i]];
		}
		ans=min(ans,time);
	}while(next_permutation(a.begin(),a.end()));
	cout<<ans;
}