/********************************************
 *Author*        :ZZZZone
 *Created Time*  : 一  3/26 10:54:23 2018
 * Ended  Time*  : 一  3/26 11:03:05 2018
*********************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

inline void OPEN(string s){
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
    //OPEN("arc92-d");
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    vector<int> c, d;
    int ans = 0;
    int pow_2 = 1;
    for(int i = 0; i <= 28; i++){
        c = a, d = b;
        for(int j = 0; j < n; j++){
            c[j] %= 2 * pow_2;
            d[j] %= 2 * pow_2;
        }
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        int l, r, sum = 0;
        for(int j = 0; j < n; j++){
            l = lower_bound(d.begin(), d.end(), pow_2 - c[j]) - d.begin();
            r = lower_bound(d.begin(), d.end(), 2*pow_2 - c[j]) - d.begin() - 1;
            sum += (r-l+1);
            l = lower_bound(d.begin(), d.end(), 3*pow_2 - c[j]) - d.begin();
            r = lower_bound(d.begin(), d.end(), 4*pow_2 - c[j]) - d.begin() - 1;
            sum += (r-l+1);
        }
        if(sum & 1) ans += pow_2;
        pow_2 *= 2;
    }
    printf("%d\n", ans);
    return 0;
}
