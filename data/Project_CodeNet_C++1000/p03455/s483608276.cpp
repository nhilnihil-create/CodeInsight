#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;
using LL = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; i++)
const int INF = numeric_limits<int>::infinity();

int main(void)
{
    LL a, b;
    cin >> a >> b;
    if ((a*b) % 2 == 0){
        puts("Even");
    }
    else{
        puts("Odd");
    }
    
    return 0;
}