#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
typedef int64_t ll;
const int MAX_N = 10000;
const int INF = 1000000000;


int main() {
	int N;
	cin >> N;
	vector<int> a(N+1);
	for (int i = 1; i <=N ; i++)
	{
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0) {
			ans += a.at(i);	
			
		}
		else {
			ans -= a.at(i);
			
		}
	}
	cout << ans << endl;

}