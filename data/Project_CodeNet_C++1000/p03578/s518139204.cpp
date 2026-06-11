#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	int n, M;
	cin >> n;
	map<int, int> m;
	int tmp;
	REP(i,0,n){
		cin >> tmp;
		++m[tmp];
	}
	cin >> M;
	string ans = "YES";
	REP(i, 0, M){
		cin >> tmp;
		if(m[tmp] == 0){
			ans = "NO";
			break;
		}
		--m[tmp];
	}
	cout << ans;
}
