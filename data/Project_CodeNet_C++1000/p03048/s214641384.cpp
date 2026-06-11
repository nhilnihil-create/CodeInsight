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
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int arr[3001] = {0};
	arr[0] = 1; 
	REP(i, r, n+1) arr[i] += arr[i-r];
	REP(i, g, n+1) arr[i] += arr[i-g];
	REP(i, b, n+1) arr[i] += arr[i-b];
	cout << arr[n];

}
