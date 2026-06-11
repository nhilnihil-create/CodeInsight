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
    string S;
    ll K;
    cin >> S >> K;
    ll count = 0;
    while(S[count] == '1')
    {
        count++;
    }
    if(count >= K)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << S[count] << endl;
    }
}