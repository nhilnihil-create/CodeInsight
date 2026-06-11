#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	int N, a[110];
	cin >> N;
	double ave = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		ave += a[i];
	}
	ave /= (double)N;
	double an = mod;
	int point = 0;
	for (int i = 0; i < N; i++) {
		if (abs(a[i] - ave) < an) {
			an = (double)abs(a[i] - ave);
			point = i;
		}
	}
	cout << point << endl;
}
