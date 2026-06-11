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

int max(int a,int b) {
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
	int n;
	int t[100009], x[100009], y[100009];
	cin >> n;
	t[0] = x[0] = y[0] = 0;
	rep(i, n) {
		cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
	}
	bool can = true;
	rep(i, n) {
		int dt = t[i + 1] - t[i];
		int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
		if (dt < dist) can = false;
		if (dist % 2 != dt % 2) can = false;
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
}
