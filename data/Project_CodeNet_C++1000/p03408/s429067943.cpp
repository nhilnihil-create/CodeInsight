#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)
typedef long long ll;

int main(){
	int N, M;
	cin >> N;

	map<string, int> str;
	rep(i, N){
		string tmp;
		cin >> tmp;
		if (str.count(tmp)) str[tmp]++;
		else str[tmp] = 1;
	}
	cin >> M;
	rep(i, M){
		string tmp;
		cin >> tmp;
		if (str.count(tmp)) str[tmp]--;
		// if (str[tmp] < 0) str[tmp] = 0;
	}
	int ans = 0;
	for (auto p: str) ans = max(p.second, ans);
	cout << ans << endl;
}