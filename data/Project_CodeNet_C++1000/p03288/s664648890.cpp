#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 rr;
    cin >> rr;
    if(rr < 1200)
    {
        cout << "ABC" << endl;
    }
    else if(rr < 2800)
    {
        cout << "ARC" << endl;
    }
    else
    {
        cout << "AGC" << endl;
    }
	return 0;
}
