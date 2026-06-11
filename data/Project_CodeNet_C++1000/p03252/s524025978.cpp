#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
using graph = vector<vector<int>>;

const double pi = 3.14159265358979323846;
const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	string s, t; cin >> s >> t;
	map<char, char> S, T;
	bool ok = true;
	for(int i = 0; i < s.size(); i++){
		char a = s.at(i), b = t.at(i);
		if(S.count(a)) if(S.at(a) != b) ok = false;
		if(T.count(b)) if(T.at(b) != a) ok = false;
		S[a] = b; T[b] = a;  
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
} 