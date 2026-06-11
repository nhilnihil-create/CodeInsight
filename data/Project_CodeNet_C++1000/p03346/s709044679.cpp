#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
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
const int MOD = 1000000009;

int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
		b[a[i]-1] = i;
	}

	int cnt = 1;
	int now = 1;
	for(int i = 0;i < n-1;i++){
		if(b[i] < b[i+1])now++;
		else{
			cnt = max(cnt,now);
			now = 1;
		}
	}

	cnt = max(now,cnt);

	cout << n - cnt << endl;
}
