#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <vector>
#include <set>

using namespace std;

#define ERROR_ID		0

#define PROCESS_ERROR(Condition)    \
{                                   \
		if (!(Condition))           \
		{                           \
			goto Exit0;             \
		}                           \
}

typedef unsigned char			BYTE;
typedef int						BOOL;
typedef unsigned long			DWORD;
typedef long long				LLONG;

inline int read() {
	int ret = 0, f = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0'&&ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret * f;
}//快读优化

int main(int argc, char* argv[])
{
	string		szNumberStr;
	int			nLength;
	int			nResult				= INT_MAX;

	cin >> szNumberStr;

	nLength = szNumberStr.size();

	for (int i = 1; i < nLength; i++)
	{
		if (szNumberStr[i] != szNumberStr[i - 1])
		{
			nResult = min(nResult, max(i, nLength - i));
		}
	}
	cout << min(nResult, nLength) << endl;
	return 0;
}