#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

vector<int> x(90001);
vector<int> y(90001);
vector<int> sum(90001);


int main(){
	int h, w, d;
	cin >> h >> w >> d;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			int a;
			cin >> a;
			x[a] = i, y[a] = j;	
		}
	}
	int q;
	cin >> q;
	vector<int> l(q), r(q);
	for (int i = 0; i < q; i++){
		cin >> l[i] >> r[i];
	}
	for (int i = 0; i < d; i++){
		sum[i] = 0;
	}
	for (int i = d; i <= h*w+1; i++){
		sum[i] = sum[i-d] + abs(x[i] - x[i-d]) + abs(y[i] - y[i-d]);
	}

	for (int i = 0; i < q; i++){
		cout << sum[r[i]] - sum[l[i]] << endl;
	}
	return  0;
}