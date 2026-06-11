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
	int a, b, c;
	int x;
	cin >> a >> b >> c >> x;

	int count = 0;

	rep(i, a+1) {
		rep(j, b+1) {
			rep(k, c+1) {
				int res = 500 * i + 100 * j + 50 * k;
				if (res == x) {
					++count;
				}
			}
		}
	}

	cout << count << endl;
}