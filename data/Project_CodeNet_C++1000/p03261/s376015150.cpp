#include<bits/stdc++.h>
using namespace std;
int main() {
	int N; cin >> N;
	string W[N];
	for(int i = 0; i < N; i++) cin >> W[i];
	for (int i = 1; i < N; i++)
	{
		if(W[i-1][W[i-1].size()-1] != W[i][0]) {
			cout << "No" << endl;
			return 0;
		}
		for (int j = 0; j < i; j++)
		{
			if(W[i] == W[j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
