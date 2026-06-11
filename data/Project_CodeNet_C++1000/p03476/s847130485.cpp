
#include <iostream>
#include <iomanip> //! for setprecision(10)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MOD = 1000000007;

class Sieve {
public:
    Sieve(int size) : sieve(size+1) {
        sieve[0] = -1;
        sieve[1] = -1;
        for (int i = 2; i <= size; ++i) {
            if (!sieve[i]) {
                sieve[i] = i;
                for (LL j = (LL) i * i; j <= (LL) size; j += i) {
                    if (!sieve[j]) {
                        sieve[j] = i;
                    }
                }
            }
        }
    }

    bool isPrime(int x) {
        return (sieve[x] == x);
    }

    void getFactors(int x, vector<int>& out) {
        while (1 < x) {
            int f = sieve[x];
            out.push_back(f);
            x /= f;
        }
    }

private:
    vector<int> sieve;
};

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    Sieve sv(100001);
    vector<int> sum(100001);
    for (int i = 3; i < 100000; i+= 2) {
        sum[i-1] = sum[i-2];
        sum[i] = sum[i-2];
        if (sv.isPrime(i) && sv.isPrime((i+1)/2)) {
            ++sum[i];
        }
    }

    int q;
    cin >> q;
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << sum[r]-sum[l-1] << '\n';
    }
    cout << endl;

    return 0;
}
