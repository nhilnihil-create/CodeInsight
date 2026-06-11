#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include <assert.h>
#include<bitset>
#include<string>
#include <deque>
#include<queue>
#include <iomanip>
#include<map>
#include <random>
#include<type_traits>
#include<stack>
#include <sstream> 
#include <limits>
#include <numeric>
#include<string.h>
#include<set>
#include <climits>
using namespace std;
typedef unsigned long long ull;
#define ll long long int
static const double PI = 3.141592653589793;
const ll INF = 100000000000000;
ll mod = 1000000007;
//typedef vector<int> V;
//typedef vector<V> VV;
//typedef vector<VV> VVV;

int main(){
	ll n;
	string s="";
	cin >> n;
	ll ind = 1;
	while (n != 0) {
		int a =abs((n % (ind*(-2)))/ind);
		n -= a * (ind);
		s = to_string(a) + s;
		ind *= -2;
	}
	if (s == "")s = "0";
	cout << s << endl;
}
