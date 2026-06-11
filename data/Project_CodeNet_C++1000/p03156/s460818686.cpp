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
	int N, A, B, P[110];
	cin >> N >> A >> B;
	int count[3] = { 0 };
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		if (P[i] <= A)count[0]++;
		else if (P[i] > B) count[2]++;
		else count[1]++;
	}
	cout << min({ count[0],count[1],count[2] }) << endl;
}
