#include<iostream> 
#include<iomanip> 
#include<vector> 
#include<map> 
#include<set> 
#include<algorithm> 
#include<numeric> 
#include<limits> 
#include<bitset> 
#include<functional> 
#include<type_traits> 
#include<queue> 
#include<stack> 
#include<array> 
#include<random> 
#include<utility> 
#include<cstdlib> 
#include<ctime>
#define _LIBCPP_DEBUG 0
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); ++i)	
using namespace std;

int max(int a, int b) {
	int max;
	if (a > b) max = a;
	else max = b;
	return max;
}
int min(int a, int b) {
	int min;
	if (a < b) min = a;
	else min = b;
	return min;
}


int main()
{
	int X, Y;
	cin >> X >> Y;
	string board[60];

	rep(i, X) {
		cin >> board[i];
	}

	int dx[8] = { -1,-1,0,1,1,1,0,-1 };
	int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

	bool can = true;
	rep(i, X) {
		rep(j, Y) {
			if (board[i][j] == '.') continue;
			if (board[i + 1][j] != '#' && board[i][j + 1] != '#' && board[i - 1][j] != '#' && board[i][j - 1] != '#') can = false;
		}
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
}
