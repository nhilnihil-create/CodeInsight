#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;

int main() {
    double ans = 0;
    ll n,k;
    cin >> n >> k;
    rep(i, 1, n+1){
        double p = 1;
        int x = i;
        while (x < k){
            p *= 0.5;
            x *= 2;
        }
        ans += p/n;
    }
    printf("%.10f\n", ans);
    return 0;
}
