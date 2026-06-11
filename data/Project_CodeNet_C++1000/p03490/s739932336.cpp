#include<bits/stdc++.h>
using namespace std;

bool can (vector<int> &V, int I) {
	vector<int> C;
	C.push_back(0);
	for(auto &T : V) {
		vector<int> D;
		for(auto &X : C) {
			D.push_back(X+T);
			D.push_back(X-T);
		}
		sort(D.begin(), D.end());
		D.erase(unique(D.begin(), D.end()), D.end());
		swap(C, D);
	}
	for(auto &T : C) {
		if(T == I) return true;
	}
	return false;
}

int main()
{
	int C = 0, X, Y;
	vector<int> V[2];
	string S;
	cin >> S >> X >> Y;
	int I = S.size();
	for(int i=0;i<(int)S.size();i++) {
		if(S[i] == 'T') {
			I = i;
			break;
		}
	}
	X -= I;
	for(int i=I;i<(int)S.size();i++) {
		if(S[i] == 'T') {
			C ^= 1;
			V[C].push_back(0);
		}
		else {
			int T = V[C].back();
			V[C].pop_back();
			V[C].push_back(T+1);
		}
	}
	puts(can(V[0], X) && can(V[1], Y) ? "Yes" : "No");
}
