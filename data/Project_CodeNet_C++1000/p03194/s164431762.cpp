#include <bits/stdc++.h>
using namespace std;

long long n, p, pa = 1, pe, tp, ti;

int main() {
    cin >> n >> p;
    if(n == 1) {
        cout << p << endl;
        return 0;
    }
    pe = sqrt(p);
    for(long long i = 2; i <= pe; ++i) {
        if(p % i == 0) {
            long long t = 0;
            tp = p;
            while(tp % i == 0) {
                tp /= i;
                ++t;
            }
            if(t >= n) pa = max(pa, i);
            tp = p;
            ti = p / i;
            t = 0;
            while(tp % ti == 0) {
                tp /= ti;
                ++t;
            }
            if(t >= n) pa = max(pa, ti);
        }
    }
    cout << pa << endl;
}