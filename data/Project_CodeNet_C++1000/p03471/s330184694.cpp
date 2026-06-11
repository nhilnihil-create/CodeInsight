#include<iostream>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>//min,max,swap,rand,reverse,sort,lower_bound
#include<functional>
#include<vector>
#include<list>
#include<map>
#include<tuple>
#include<cmath>//abs, sin, cos
#include<bitset>
using namespace std;

int main()
{
	int N, Y, t, flag=0, count=0;
	int i, j, k;
	cin >> N >> Y;
	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N-i; j++) {
			//if (N > i + j)
				//break;
			if ((10000 * j) + (5000 * i) + (1000 * (N - j - i)) == Y && i + j + (N - i - j) <= N) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (flag == 1) {
		cout << j << " " << i << " " << N-j-i << endl;
	}
	else
		cout << "-1 -1 -1" << endl;

	return 0;
}