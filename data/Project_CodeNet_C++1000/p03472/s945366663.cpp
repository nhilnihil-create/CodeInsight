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
const int MOD = 1000000007;
int main(){
	int n,h;
	cin >> n >> h;
	vector<int> b(n);
	int a = 0;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		a = max(a,x);
		b[i] = y;
	}

	sort(b.begin(),b.end(),greater<int>());

	int cnt = 0;
	for(int i = 0;i < n;i++){
		if(a < b[i]){
			h -= b[i];
			cnt++;
		} 
		else{
			cnt += (h + a - 1) / a;
			cout << cnt << endl;
			return 0;
		}
		if(h <= 0){
			cout << cnt << endl;
			return 0;
		}
	}

	if(h > 0){
		cout << cnt + (h + a-1) / a << endl;
	}
}
