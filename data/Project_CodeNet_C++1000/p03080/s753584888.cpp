#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int main() {
	char s;
	int N,r=0,b=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s == 'R')r++;
		else b ++;
	}
	cout << (r > b ? "Yes" : "No");
}
