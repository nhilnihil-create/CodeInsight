#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdlib.h>
#define ll long long
#define MOD_P 1000000007
using namespace std;

int main()
{
	int H,W,h,w;

	cin >> H >> W >> h >> w;
	
	printf("%d", (H - h) * (W - w));
	
	return 0;
}