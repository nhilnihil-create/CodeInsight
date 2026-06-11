#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n,z,w;
	cin >> n >> z >> w;
	vector<int> a(n);
	for(int i = 0;i < n;i++)cin >> a[i];

	if(n == 1){
		cout << abs(a[0] - w) << endl;
	}
	else{
		cout << max(abs(w-a[n-1]),abs(a[n-1] - a[n-2])) << endl;
	}

	return 0;
}
