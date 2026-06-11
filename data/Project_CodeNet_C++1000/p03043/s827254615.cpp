#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 1; i <= (n); i++)


int main() {
    int n, k;
    cin >> n >> k;
    double ans = 0,tmp = 1;
   
    double b = 0;
    rep(i, n) {
        double a = 1,cnt = i,c = 1;
        while (cnt < k) {
            cnt *= 2;
            c *= 2;
        }
        c *= n;
        a *= (double)1 / c;
        
        b += a;
    }
    b *= tmp;

    ans += b;
    printf("%.16f", ans);

    return 0;
}