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
	int N;
	string A, B, C;
	cin >> N >> A >> B >> C;
	int an = 0;
	for (int i = 0; i < N; i++)
	{
		if ((A[i] != B[i]) && (A[i] != C[i]) && (B[i] != C[i])) an += 2;
		else if (A[i] == B[i] && A[i] == C[i]);
		else an++;
	}
	cout << an << endl;
}
