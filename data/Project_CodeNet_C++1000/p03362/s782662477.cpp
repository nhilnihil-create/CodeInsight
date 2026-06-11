#include <iostream>
#include <vector>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;

const int mm = 55600;

void sieve(ll m, vector<bool> &is_prime) {
    is_prime[0] = false; is_prime[1] = false;
    for (int i=2;i<m;++i) {
        if (!is_prime[i]) continue;
        for (int j=i*2;j<m;j+=i) is_prime[j] = false;
    }
}

int main() {
    int n; cin >> n;

    vector<bool> is_prime(mm, true);
    sieve(mm, is_prime);

    int cnt = 0;

    for (int i = 0; i <= 55555; ++i) {
        if (cnt == n) break;
        if (is_prime[i]) {
            if (i % 5 == 1) {
                cout << i << " ";
                cnt++;
            }
        }
    }

    cout << endl;
}