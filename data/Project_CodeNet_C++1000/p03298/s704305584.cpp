#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
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
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
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
#define rep(i,a,n) for(ll i =(a);i<(n);i++)
#define urep(i,a,n) for(ll i = (a);i>=(n);i--)
#define all(x) (x).begin();(x).end()
typedef long long ll;
using namespace std;
ll Power(ll a,ll x) {
	int num = a;
	rep(i, 1, x)num *= a;
	return num;
}

ll N, ans;
string S;
string s1, s2;
int main() {
	cin >> N >>S;
	rep(i, 0, N)s1 += S[i];
	urep(i, N*2-1, N)s2 += S[i];
	map<pair<string,string>, ll> m1,m2;
	rep(i, 0, Power(2, N)) {
		bitset<18> b1(i);
		string tmp1,tmp2,num1,num2;
		rep(j, 0, N) {
			if (b1[j]) {
				tmp1 += s1[j];
				tmp2 += s2[j];
			}
			else {
				num1 += s1[j];
				num2 += s2[j];
			}
		}
		pair<string, string> num;
		num.first = tmp1; num.second = num1;
		m1[num]++;
		num.first = tmp2; num.second = num2;
		m2[num]++;
	}
	for (map<pair<string,string>, ll>::iterator itr = m1.begin(); itr != m1.end(); ++itr) {
		ans += itr->second*m2[itr->first];
	}
	cout << ans << endl;
	cin >> ans;
	return 0;
}