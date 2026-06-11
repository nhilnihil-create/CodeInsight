#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }



int main()
{
    int c[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(c[j][i] - c[j + 1][i] != c[j][i + 1] - c[j + 1][i + 1])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    // // a1 - a2系は終わった
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(c[j][i] - c[j][i+1] != c[j + 1][i] - c[j + 1][i + 1])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}