#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string s;
int n;

bool check(){
	if(s[0] == '0') return false;
	if(s[n-1] == '1') return false;
	if(s[n-2] == '0') return false;

	for(int i = 1; i < n - 2 - i; i++){
		if(s[i] != s[n - 2 - i]) return false;
 	}

	return true;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	n = s.size();

	if(!check()){
		cout << -1 << endl;
		return 0;
	}

	vector<pii> ans;
	int t = 1;
	for(int i = 1; i < n - 1; i++){
		if(s[i] == '1'){
			ans.push_back({t, i + 1});
			t = i + 1;
		}
	}
	ans.push_back({t, n});

	t = n;
	for(int i = n - 2; i >= 1; i--){
		if(s[i] == '0'){
			ans.push_back({i + 1, t});
		}else{
			t = i + 1;
		}
	}

	for(pii p : ans){
		cout << p.first << " " << p.second << endl;
	}
}
