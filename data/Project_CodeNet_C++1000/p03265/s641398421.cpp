#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	int ax,ay,bx,by;
	cin>>ax>>ay>>bx>>by;
	int x=bx-ax,y=by-ay;
	cout<<bx-y<<" "<<by+x<<" "<<ax-y<<" "<<ay+x;
}