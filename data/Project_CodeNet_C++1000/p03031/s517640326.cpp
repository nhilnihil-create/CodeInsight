#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n, m;
vector<int> vec[15];
int p[15];
 
int main(void)
{
	cin >> n >> m;
	int k, x;
	for(int i = 1; i <= m; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> x;
			x--;
			vec[i].push_back(x);
		}
	}
	for(int i = 1; i <= m; i++) cin >> p[i];
	
	int N = 1<<n, ans = 0;
	for(int i = 0; i < N; i++){
		bool flag = true;
		for(int j = 1; j <= m; j++){
			int cnt = 0;
			for(int k = 0; k < vec[j].size(); k++){
				if(i & (1<<vec[j][k]))cnt++;
			}
			if(cnt%2 != p[j]) flag = false;
		}
		if(flag) ans++;
	}
	cout << ans << endl;
	
	return 0;
}