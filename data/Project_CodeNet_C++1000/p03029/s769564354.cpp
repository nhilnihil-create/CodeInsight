#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
 
int main() {
	int a, p;
	cin >> a >> p;
	a *= 3;
	a = a + p;
	cout << a / 2;
	return 0;
}