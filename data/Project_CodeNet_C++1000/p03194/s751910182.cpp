#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF 1000000000
#define MOD 1000000007


long long power(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    
    long long result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int main(int argc, char *argv[]) {
    long long N, P;
    cin >> N >> P;
    
    vector<long long> v;
    map<long long, long long> m;
    ll i;
    
    if (N == 1) {
        // do nothing
    } else {
        for (i = 2; i * i <= P; i++) {
            while (P % i == 0) {
                m[i]++;
//                v.push_back(i);
                P /= i;
            }
        }
    }
    
    if (P != 1) {
//        v.push_back(P);
            m[P]++;
    }
    
    long long ans = 1;
    for (auto p: m) {
        if (p.second < N) {
            continue;
        } else {
            ans *= power(p.first, (p.second / N));
        }
        //cout << p.first << " -> " << p.second << endl;
    }
    cout << ans << endl;
    
    return 0;
}
