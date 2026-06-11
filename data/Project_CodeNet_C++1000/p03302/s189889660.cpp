#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;

typedef long long Int;
typedef pair<Int,Int> P;
#define print(x) cout<<(x)<<endl

#define INF10 10000000000
#define INF5 100000
#define EPS 1e-10
#define MOD 1000000007
 
char c[] = "MUJIN";

int main() {
	int a, b;
	cin >> a >> b;
	if (a + b == 15)print('+');
	else if (a*b == 15)print('*');
	else print("x");


	return 0;
}