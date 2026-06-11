#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N;
	cin >> N;

	map<string, bool> used;
	char prev;
	rep(i, N){
		string w;
		cin >> w;
		if (used.count(w) || (i != 0 && w.at(0) != prev)){
			cout << "No" << endl;
			return 0;
		}
		used[w] = true;
		prev = w.at(w.size() - 1);
	}
	cout << "Yes" << endl;
}