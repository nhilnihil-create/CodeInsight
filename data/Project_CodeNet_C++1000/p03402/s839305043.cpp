
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;

const ll MOD_CONST = 1000000007;



int main()
{

	int a, b;
	cin >> a >> b;

	

	vector<string> ans(100);
	for (int i = 0; i < 50; i++) {
		ans[i] = string(100, '#');
	}

	for (int i = 50; i < 100; i++) {
		ans[i] = string(100, '.');
	}


	vector<vector<int>> direction{ {1,0},{0,1},{-1,0},{0,-1} };

	for (int i = 0; i < 49; i+=2) {
		for (int j = 0; j < 100; j += 2) {
			if (a == 1) {
				break;
			}


			ans[i][j] = '.';
			a--;
			//cout << ans[i][j] << endl;

		}
	}


	for (int i = 51; i < 100; i+=2) {
		for (int j = 0; j < 100; j += 2) {
			if (b == 1) {
				break;
			}


			ans[i][j] = '#';
			b--;
			//cout << ans[i][j] << endl;

		}
	}



	cout << 100 << " " << 100 << endl;
	for (int i = 0; i < 100; i++) {
		cout << ans[i] << endl;
	}

	
}  

