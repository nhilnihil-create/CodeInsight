
#include<iostream>
#include <string> 
#include <vector>  
#include<math.h>
#include <algorithm>
#include<iomanip>
#include<map>
#define INF 1000000000
#define LM 55555
#define LL long long
using namespace::std;

LL N, M, K, ans, num, H, W, P,an[10000000];
bool sosu[10000000];
string S;

	vector<LL>v;
	map<LL, LL>m;
int main() {
	cin >> N >> P;

	if (N > P) {
		cout << 1 << endl;
		return 0;
	}
	K = 0;

	LL a = sqrt(P);
	LL c = 2;
	LL con = 0;
	while (a>c) {
		if (P%c==0){
			v.push_back(c);

			P=P / c;
		}
		else {
			c++;
		}
	}
	ans = 1;
	if (P > 1)v.push_back(P);
	LL n,d;
	n = 1;
	d = 0;
	for (int i = 0; i < v.size(); i++) {
		if (n == v[i]) {
			d++;
		}
		else {
			ans = ans*pow(n, d / N);
			n = v[i];
			d=1;
		}
	}

	ans = ans*pow(n, d / N);
	cout << ans << endl;

	return 0;



}