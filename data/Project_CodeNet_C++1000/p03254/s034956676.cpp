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
#define INT_MAX 2147483647
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

int main() {
	int n;
	int x;
	int a[110];

	cin >> n >> x;
	rep(i, n) {
		cin >> a[i];
	}
	sort(a, a + n);

	int count = 0;
	bool t = false;
	rep(i, n) {
		x -= a[i];
		if (i == n - 1 && x > 0) {
			count--;
		}
		if (x < 0) {
			break;
		}
		else {
			++count;
		}
	}
	cout << count << endl;

}