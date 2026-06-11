#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;

string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	int n = (int)s.size();
	s = ' ' + s;
		
	if(s[1] == '0'){
		cout << "-1\n";
		return 0;
	}

	if(s[n] == '1'){
		cout << "-1\n";
		return 0;
	}

	for(int i = 1; i < n; i++){
		if(s[i] != s[n - i]){
			cerr << "wher\n";
			cerr << i << ' ' << n - i << '\n';
			cout << "-1\n";
			return 0;
		}
	}

	int last = 1;

	int cur = 1;
	int cnt = 2;
	cout << "1 2\n";

	for(int i = 2; i < n; i++){
		if(s[i] == '0'){
			continue;
		}
		
		//cerr << last << ' ' << i << '\n';
		cur = cnt++;
		for(int j = 1; j <= i - (last + 1); j++){
			//edg.push_back(make_pair(cur, cnt++));
			cout << cur << ' ' << cnt++ << '\n';
		}
		
		cout << cur << ' ' << cnt << '\n';
		last = i;
	}

	return 0;
}