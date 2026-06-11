#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> d(N);
	REP(i, N){
		cin >> d[i];
	}

	bitset<100> s;
	REP(i, N){
		s.set(d[i] - 1, 1);
	}
	cout << s.count() << endl;
}
