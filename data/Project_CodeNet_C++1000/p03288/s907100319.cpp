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

    int R;
    cin >> R;
    if (R < 1200) cout << "ABC" << endl;
    else if (R < 2800) cout << "ARC" << endl;
    else cout << "AGC" << endl;
    
    return 0;
}