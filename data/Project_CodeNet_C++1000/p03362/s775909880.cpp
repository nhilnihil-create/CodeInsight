#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

bool isprime(int x) {
    int n = 2;
    while (n * n <= x) {
        if (x % n == 0) return false;
        n++;
    }
    return true;
}

int main() {

    int N;
    cin >> N;
    int x = 11;
    while (N > 0) {
        if (isprime(x)) {
            cout << x << (N > 1 ? " " : "");
            N--;
        }
        x += 5;
    }

    cout << endl;
    
    return 0;
}