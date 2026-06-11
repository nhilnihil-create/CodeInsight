#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main() {
	string S;
	int K;
	cin >> S >> K;
	vector<string> A;
	for (size_t i = 0; i < S.size(); i++)
	{
		for (size_t j = 1; j <= K; j++)
		{
			if (i + j >= S.size()+1)break;
			A.push_back(S.substr(i, j));
		}
	}
	sort(A.begin(), A.end());
	int now = 1;

	for (size_t i = 0; i < A.size()-1; i++)
	{
		if (A.at(i) != A.at(i + 1))now++;
		if (now == K) { 
			cout << A.at(i + 1); 
			return 0;
		}
	}
	cout << A.at(S.size() - 1);
}