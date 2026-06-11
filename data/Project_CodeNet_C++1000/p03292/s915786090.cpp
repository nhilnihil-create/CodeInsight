#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    cout << (max({A1, A2, A3}) - min({A1, A2, A3})) << endl;

    return 0;
}