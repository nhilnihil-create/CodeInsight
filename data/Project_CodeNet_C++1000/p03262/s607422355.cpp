#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#define ll long long
#define pi (acos(-1))
using namespace std;
int main()
{
    unsigned ll n, x;
   cin >> n >> x;
    vector<unsigned ll> vec(n);

    for (unsigned ll i = 0; i != n; ++i) { cin >> vec[i]; }

    unsigned ll a = 0;
    long long tmp = 0;
    for (auto &i : vec)
    {
        tmp = i - x;
        a = gcd(a, abs(tmp));
    }

    std::cout<<a<<std::endl;

    return 0;
}
