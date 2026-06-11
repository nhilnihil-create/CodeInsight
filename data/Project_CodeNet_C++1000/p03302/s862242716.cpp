#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
#ifndef ONLINE_JUDGE
    scanf("%lld", &a);
#else
    scanf("%I64d", &a);
#endif
    return a;
}

int main() {
    int a = gi();
    int b = gi();
    if (a+b == 15)
        printf("+\n");
    else if (a*b == 15)
        printf("*\n");
    else
        printf("x\n");

    return 0;
}
