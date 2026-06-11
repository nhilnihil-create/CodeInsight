#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<string> s(N);
	REP(i, N){
		cin >> s[i];
	}

	int M;
	cin >> M;
	vector<string> t(M);
	REP(i, M){
		cin >> t[i];
	}

	int max_point = 0;
	REP(i, N){
		string selected = s[i];
		int point = 0;
		REP(j, N){
			if(s[i] == s[j])
				point++;
		}
		REP(j, M){
			if(s[i] == t[j])
				point--;
		}
		if(point > max_point)
			max_point = point;
	}
	cout << max_point << endl;
}
