#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

int a = 0, b = 0;

bool yymm() {
	return (b >= 1 && b <= 12);
}

bool mmyy() {
	return (a >= 1 && a <= 12);
	
}

void solve() {
	for(int i = 0; i < 2; i++) {
		char c;
		cin >> c;
		if(i == 0) a += (c - '0') * 10;
		if(i == 1) a += (c - '0');
	}
	
	
	for(int i = 0; i < 2; i++) {
		char c;
		cin >> c;
		if(i == 0) b += (c - '0') * 10;
		if(i == 1) b += (c - '0');
	}
	
	if(yymm() && mmyy()) cout << "AMBIGUOUS" << endl;
	else if(yymm()) cout << "YYMM" << endl;
	else if(mmyy()) cout << "MMYY" << endl;
	else cout << "NA" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}