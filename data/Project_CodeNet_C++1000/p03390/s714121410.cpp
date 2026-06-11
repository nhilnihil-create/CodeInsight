#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <cmath>
#include <string>

using namespace std;

long long max(long long a,long long b) {
    if(a > b)
        return a;
    else
        return b;
}

long long min(long long a,long long b) {
    if(a < b)
        return a;
    else
        return b;
}

long long max_mp(long long x,long long y,long long f) {
    long long k = ((-1) * x + y + f + 1) / 2;
    k = max(0,min(y-x,k));
    return (x + k) * (y + f - k);
}

long long max_k(long long a,long long b) {
    if(a == 0)
        return 0;
    pair<long long,long long> r;
    r.first = 0;
    r.second = a - 1;
    while(r.second - r.first > 1) {
        long long mid = (r.first + r.second) / 2;
        if(max_mp(1, mid, b) < a * b)
            r.first = mid;
        else
            r.second = mid;
    }
    if(max_mp(1, r.second, b) < a * b)
        r.first = r.second;
    else
        r.second = r.first;
    return r.first;
}

long long solve(long long a,long long b) {
    long long ret = 0,x = max_k(a,b),y = max_k(b, a);
    ret = x + y + min(a - x - 1,b - y - 1);
    return ret;
}

int main(void) {
    long long q,a,b;
    cin >> q;
    for(long long i = 0;i < q;i++) {
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
