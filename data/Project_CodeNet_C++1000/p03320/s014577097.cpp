#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}


long long deg(long long x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}


vector<long long> cands(long long x) {
    vector<long long> c;
    long long pw = 1;
    for (int i = 0; i < 18; i++) {
        long long a = (x / pw % 10);
        if (a != 9) {
            c.push_back(x + pw);
        }
        pw *= 10;
    }
    return c;
}


void solve(long long K) {
    vector<long long> data;
    for (int j = 1; j <= 10000; j++) {
        long long x = j;
        for (int i = 0; i <= 15; i++) {
            if( x > 1e16) break;
            bool ok = true;
            for (auto y: cands(x)) {
                if( 1. * x / deg(x) > 1. * y / deg(y)){
                    ok = false;
                    break;
                }
            }
            if(ok){
                data.push_back(x);
            }
            x = x * 10 + 9;
        }
    }
    sort(data.begin(), data.end());
    data.erase(unique(data.begin(), data.end()), data.end());


    for(int i = 0 ; i < K ; i++){
        cout << data[i] << endl;
    }

}

int main() {
    long long K;
    scanf("%lld", &K);
    solve(K);
    return 0;
}
