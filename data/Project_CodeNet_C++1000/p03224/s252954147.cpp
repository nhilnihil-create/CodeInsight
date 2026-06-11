#include"bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define INF 1e+9

int dan=2,j=1;

string bowling_pin(int x) {
	int i;
	for (i=2;i<100001; i++)
	{
		if (x == j) return "Yes";
		j += i;
		dan++;
	}
	return "No";
}

int main() {
	int n,x,y;
	cin >> n;
	string ans;
	vector<vector<int>> s(200000);

	ans = bowling_pin(n);

	cout << ans << endl;

	
	int cnt = 1;
	if (ans == "Yes") {
		for(int i=1;i<dan;i++)
			for (int j = i + 1; j <= dan; j++) {
				s[i].push_back(cnt);
				s[j].push_back(cnt);
				cnt++;
			}
      cout<<dan<<endl;

		for (int i = 1; i <= dan; i++) {
			cout << s[i].size();
			for (int j = 0; j < s[i].size(); j++) {
				cout << " " << s[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}