//written by libra9z
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <valarray>
#include <utility>
#include <numeric>
#include <memory>
#include <functional>
#include <stdexcept>
#include <typeinfo>
#include <limits>
#include <complex>
#include <locale>
using namespace std;
#define Debug(x) cerr << #x << " = " << x << endl
#define Debug22(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define Debug2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define Debug3(x,y,z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = ("<<x<<", "<<y<<", "<<z<<")\n";
#define Debug_arr(v,n) for(int i=0;i<n;++i) cerr<<#v<<"["<<i<<"]"<<" = "<<v[i]<<endl;
#define SET(p,v) fill((__typeof(**p)*)p,(__typeof(**p)*)p+sizeof(p),v);
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define prl cerr << "called: " << __LINE__ << endl
#define all(s) s.begin(),s.end()
const int INF=1e9;
string s;
int bit;
int dp[1<<26];
int main()
{
	for (int i=1;i<1<<26;++i)
	{
		dp[i]=INF;
	}
	cin>>s;
	for (auto x:s)
	{
		bit^=1<<(x-'a');
		for (int i=0;i<26;++i)
		{
			dp[bit]=min(dp[bit],dp[bit^(1<<i)]+1);
		}
	}
	cout<<max(1,dp[bit])<<endl;
	return 0;
}