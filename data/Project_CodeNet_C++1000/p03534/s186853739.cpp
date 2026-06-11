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
const int inf=2e9;
string s;
int a[3];
int main()
{
	cin>>s;
	if (s.size()==1)
	{
		cout<<"YES";
		return 0;
	}
	for (auto x:s)
	{
		a[x-'a']++;
	}
	sort(a,a+3);
	if (s.size()==2)
	{
		if (a[0]==0 && a[1]==0)
		{
			cout<<"NO";
		}
		else
		{
			cout<<"YES";
		}
		return 0;
	}
	int tmp=a[0];
	for (int i=0;i<3;++i)
	{
		a[i]-=tmp;
	}
	if (a[2]>=2)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
	return 0;
}