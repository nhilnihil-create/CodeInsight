#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T3;

int main(){
	int n,m;
	cin >> n >> m;
	int p = 1 << m;
	cout << p * (1900 * m + 100 * (n-m)) << endl;
}
