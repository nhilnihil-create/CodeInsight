#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;
typedef pair<int, int> P;

int a[60];
int main()
{
	int N; cin >> N;
	int max = 0, point = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (abs(a[i]) > max) {
			max = abs(a[i]);
			point = i;
		}
	}
	cout << N * 2 - 1 << endl;
	for (int i = 0; i < N; i++) {
		cout << point + 1 << " " << i + 1 << endl;
	}
	if (a[point] >= 0) {
		for (int i = 0; i < N - 1; i++) {
			cout << i + 1 << " " << i + 2 << endl;
		}
	}
	else {
		for (int i = N - 1; i > 0; i--) {
			cout << i + 1 << " " << i << endl;
		}
	}
}
