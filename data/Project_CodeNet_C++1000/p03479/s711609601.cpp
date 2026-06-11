#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <stdio.h>
#include <bitset>
#include<math.h>
#include<list>
#include<map>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef unsigned long long ull;
#define PI 3.14159265358979323846  
#define MOD 1000000007;
typedef pair<int, int> P;


int main() {
	ull x,y;
	int ans=0;
	cin >> x >> y;
	while (x <= y) {
		x *= 2;
		ans++;
		//cout << "ok";
	}
	cout << ans << endl;
}
