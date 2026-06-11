#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

int main()
{
	int N, Y;
	cin >> N >> Y;

	bool isEnable = false;
	int ansA, ansB, ansC;
	ansA = -1;
	ansB = -1;
	ansC = -1;
	rep(A, N+1)
	{
		rep(B, N-A+1)
		{
			if (9000 * A + 4000 * B >= Y - 1000 * N)
			{
				if (9000 * A + 4000 * B == Y - 1000 * N)
				{
					ansA = A;
					ansB = B;
					ansC = N - A - B;
					isEnable = true;
				}
				break;
			}
		}

		if (isEnable)
		{
			break;
		}
	}

	cout << ansA << " " << ansB << " " << ansC << endl;
	
	return 0;
}