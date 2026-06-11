#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using lli = int_fast64_t;
using ulli = uint_fast64_t;
#define debug(x) cerr << #x << " : " << x << endl
#define debugv(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x << ", ";}cerr << endl
#define debugst(x) auto xt = x;cerr << #x << " : {";for(int i=0;i<x.size();i++){ cerr << xt.top() << ", ";xt.pop();}cerr << endl
#define debugvp(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x.first << " : " << value_of_x.second << ", ";}cerr << endl

const lli MOD = 1000000007;
const lli LIMIT = 1000000000000000000 * 5;
const int tenfive = 100000;
int main() {
	int N;
	cin >> N;
	cout << (N - 2) * 180 << endl;
	return 0;
}
