#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
	int N, c[26][100] = {};
	string S[3];
	cin >> N;
	int  ans = N * 3;
	for (int i = 0; i < 3; i++)cin >> S[i];
	for (int i = 0; i < N; i++)
	{
		if (S[1][i] == S[0][i] && S[0][i] == S[2][i])ans -= 3;
		else if (S[1][i] == S[0][i] || S[1][i] == S[2][i] || S[2][i] == S[0][i])ans -= 2;
		else ans--;
	}
	cout << ans;
}
