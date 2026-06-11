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
    int N;
    cin >> N;
    int price = 0;
    if (N % 4 == 0 || N % 7 == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i <= 25; i++)
        {
            for (int j = 0; j <= 14; j++)
            {
                if (N == 4 * i + 7 * j)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
