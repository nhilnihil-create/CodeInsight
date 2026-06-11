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

int N;

void func(ll cur,ll use, ll &counter)
{
    if(cur > N) return;
    if(use == 0b111) counter++;

    func(cur*10 + 7, use | 0b001, counter);
    func(cur*10 + 5, use | 0b010, counter);
    func(cur*10 + 3, use | 0b100, counter);
}

int main()
{
    cin >> N;
    ll res = 0;
    func(0,0,res);
    cout << res << endl;
}