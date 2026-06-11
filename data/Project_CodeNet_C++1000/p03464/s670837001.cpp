#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define llong long long
#define INF (__INT32_MAX__ / 2)
#define EPS 10e-8
#define MAX_K 100000

using namespace std;
typedef pair<llong, llong> ipair;
llong modulo(llong left, llong right) { return (left % right + right) % right; }

llong K, A[MAX_K];

ipair solve() {
    ipair res = make_pair(2, 2);
    for(int i = K - 1; i >= 0; --i) {
        llong x_1 = (res.first + A[i] - 1) / A[i] * A[i];
        llong x_k = res.second / A[i] * A[i];

        if(x_1 > x_k)
            return make_pair(-1, -1);
        else
            res = make_pair(x_1, x_k + A[i] - 1);
    }
    return res;
}

int main(int argc, char **argv) {
    cin >> K;
    for(int i = 0; i < K; ++i)
        cin >> A[i];
    
    ipair res = solve();
    if(res.first != -1)
        cout << res.first << " " << res.second << endl;
    else
        cout << "-1" << endl;
}