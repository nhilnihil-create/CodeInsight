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
	int N; cin >> N;
	int count = 0;
	while (N > 0) {
		if (N % 10 == 2) {
			count++;
		}
		N /= 10;
	}
	cout << count << endl;
}