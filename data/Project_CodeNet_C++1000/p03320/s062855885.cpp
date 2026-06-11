#include <bits/stdc++.h>
using namespace std;

int S(long long n) {
    int ret = 0;
    while(n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

double f(long long n) {
    return (double)(n) / S(n);
}

int main() {
    vector<long long> res;

    long long base = 1;
    for(int i=0; i<15; ++i) {
        for(int j=1; j<150; ++j) {
            res.push_back(base * (j + 1) - 1);
        }
        base *= 10;
    }
    sort(begin(res), end(res));
    res.erase(unique(begin(res), end(res)), end(res));

    for(int i=0; i<res.size(); ++i) {
        for(int j=i+1; j<res.size(); ++j) {
            if(f(res[i]) > f(res[j])) {
                res.erase(begin(res) + i--);
                break;
            }
        }
    }

    int K;
    cin >> K;
    for(int i=0; i<K; ++i) cout << res[i] << endl;
}