#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
using namespace std;
typedef long long int lli;
int main(void)
{
    lli X, Y;
    cin >> X >> Y;
    if (X % Y == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        cout << X << endl;
    }
    return 0;
}