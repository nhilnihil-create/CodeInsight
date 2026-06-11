#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;

int A, B;

int main() {
	
	cin >> A >> B;
	int ans = 0;
	for (int i = A; i <= B; i++)
	{
		bool ok = true;
		string tmp = to_string(i);
		int N = tmp.size(); N--;
		for (int j = 0; j <= N; j++)
		{
			
			if (tmp.at(j)!= tmp.at(N))
			{
				ok = false;
				break;
			}
			N--;
		}
		if (ok)
		{
			ans++;
		}
		
	}
	cout << ans << endl;
}