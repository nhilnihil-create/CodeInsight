#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	string S[N+1];
	int P[N+1];
	set<string> city;
	set<int> b;
	rep(i,N) {
		cin >> S[i+1] >> P[i+1];
		city.insert(S[i+1]);
		b.insert(100-P[i+1]);
	}

	for (string s: city) {
		for (int bp: b) {
			for (int i = 1; i <= N; i++) {
				if (s==S[i]  && bp==100-P[i]) cout << i << endl;
			}
		}
	}
	
	return 0;
}
