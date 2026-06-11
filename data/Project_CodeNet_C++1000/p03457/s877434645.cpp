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
	int n;
	cin >> n;
	vector<int> t(n);
	vector<int> x(n);
	vector<int> y(n);
	for(int i = 0;i < n;i++){
		cin >> t[i] >> x[i] >> y[i];
	}

	int nowx = 0;
	int nowy = 0;
	int nowt = 0;
	for(int i = 0;i < n;i++){
		if(abs(nowt - t[i]) < abs(nowy - y[i]) + abs(nowx - x[i])){
			cout << "No" << endl;
			return 0;
		}
		else if(abs(nowt - t[i]) % 2 != (abs(nowy - y[i]) + abs(nowx - x[i])) % 2){
			cout << "No" << endl;
			return 0;
		}
		nowt = t[i];
		nowx = x[i];
		nowy = y[i];
	}

	cout << "Yes" << endl;
}
