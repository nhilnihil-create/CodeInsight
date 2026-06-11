#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define PI 3.141592653589793238
#define INF 1050000000

using vi = vector<int>;


int main() {

	vector<vector<char>> C(2, vector<char>(3));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> C[i][j];
		}
	}

	if (C[0][0] != C[1][2] || C[0][1] != C[1][1] || C[0][2] != C[1][0]) {

		cout << "NO" << endl;

	} else{

		cout << "YES" << endl;

	}


	return 0;
}