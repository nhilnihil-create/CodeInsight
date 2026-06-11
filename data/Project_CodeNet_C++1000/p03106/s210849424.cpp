#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main() {
	int A, B, K;
	cin >> A >> B >> K;
	vector<int> vec;
	int N = min(A, B);
	for (int i = 1; i <= N; i++)
	{
		if (A%i==0 && B%i==0)
		{
			vec.push_back(i);
			
		}
	}
	reverse(vec.begin(), vec.end());
	cout << vec.at(K - 1) << endl;
}