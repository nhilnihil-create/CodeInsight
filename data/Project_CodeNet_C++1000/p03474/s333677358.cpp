
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;



int main() {
	int A, B;
	string S;
	cin >> A >> B >> S;
	rep(i, A) {
		if (S.at(i) < '0' || S.at(i) > '9') { 
			cout << "No" << endl;
			return 0;
		}
	}
	if (S.at(A)!='-')
	{
		cout << "No" << endl;
		return 0;
	}

	for (int i = A+1; i < S.size(); i++)
	{
		if (S.at(i) < '0' || S.at(i) > '9') {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
