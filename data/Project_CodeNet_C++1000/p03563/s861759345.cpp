#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define int long long
int R;
int G;

signed main()
{
    scanf("%lld", &R);
    scanf("%lld", &G);

    printf("%lld\n", 2 * G - R);
    return 0;
}
