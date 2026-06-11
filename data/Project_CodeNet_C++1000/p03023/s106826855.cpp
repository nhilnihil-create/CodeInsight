#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
#define PLL pair<ll,ll>
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i,n) for (ll i = 1; i <= (ll)(n); i++)
#define repR(i,n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define rep1R(i,n) for (ll i = (ll)(n); i >= 1; i--)
#define loop(i,a,B) for (ll i = a; i B; i++)
#define loopR(i,a,B) for (ll i = a; i B; i--)
#define all(v) v.begin(), v.end()
#define fcout cout<<fixed<<setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const unsigned int BIT_FLAG_0 = (1 << 0);
const unsigned int BIT_FLAG_1 = (1 << 1);
const unsigned int BIT_FLAG_2 = (1 << 2);
const unsigned int BIT_FLAG_3 = (1 << 3);
const unsigned int BIT_FLAG_4 = (1 << 4);
const unsigned int BIT_FLAG_5 = (1 << 5);
const unsigned int BIT_FLAG_6 = (1 << 6);
const unsigned int BIT_FLAG_7 = (1 << 7);
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 1000000000000000000;

string S, T, U;
char V[1100000];
ll ANS = 0, SUM = 0, NOW = 0, N, M, A, B, C, D, E, F[1100000] = { 0 }, G[1100000] = { 0 };
double n, m, a, b, c, d, e;
bool ans = 0, now = 0, sum = 0;
PLL ARM[1100000];
int main(void) {
	cin >> N;
	cout << (N - 2) * 180;
	return 0;
}