//Author : pakhandi
//
using namespace std;

#include <bits/stdc++.h>

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

#define IGNORE cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

const ll INF = (1LL << 58);

#ifdef BUGGY
	bool DEBUG = 1;
#endif
#ifndef BUGGY
	bool DEBUG = 0;
#endif

const int MAX_LIMIT = 200005;

string S;
int A[MAX_LIMIT];
map<int, int> ans;

int main()
{
	cin >> S;
	int limit = S.size();

	A[0] = (1<<(S[0] - 'a'));
	for(int i = 1; i < limit; i++) {
		A[i] = A[i - 1] ^ (1<<(S[i] - 'a'));
	}

	ans[A[0]] = 1;
	for(int i = 1; i < limit; i++) {
		int thisMin = MOD;
		for(int j = 0; j < 26; j++) {
			int mask = (1<<j)^A[i];
			if(ans.find(mask) != ans.end()) {
				thisMin = min(thisMin, ans[mask] + 1);
			}
		}
		if(A[i] == 0 || (A[i] && (!(A[i]&(A[i]-1))))) {
			thisMin = 1;
		}
		if(ans.find(A[i]) != ans.end()) {
			thisMin = min(thisMin, ans[A[i]]);
		}
		ans[A[i]] = thisMin;
	}

	cout << ans[A[limit - 1]];

	return 0;
}
/*
	Powered by Buggy Plugin
*/