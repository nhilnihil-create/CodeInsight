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
    int N, K;
    cin >> N >> K;
    if (N % K == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
    return 0;
}
