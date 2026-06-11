#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
const int MAXN = 250005;
const int MAXV = 1000005;

map<lint, int> mp;

int main(){
	int n; scanf("%d",&n);
	lint sum = 0;
	mp[sum]++;
	lint ret = 0;
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		sum += x;
		ret += mp[sum];
		mp[sum]++;
	}
	cout << ret << endl;
}
