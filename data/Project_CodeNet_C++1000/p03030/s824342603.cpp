#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	pair<pair<string,int>,int> cpr[N];
	rep(i,N) {
		string s;
		int p;
		cin >> s >> p;
		cpr[i] = make_pair(make_pair(s,100-p),i+1);
	}

	sort(cpr,cpr+N);
	rep(i,N) cout << cpr[i].second << endl;

	return 0;
}
