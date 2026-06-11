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
    
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    int sum = A[0];

    long long count = 0;

    int l = 0, r = 0;

    while (l < N) {
        if (r < N - 1 && (sum & A[r + 1]) == 0) {
            r++;
            sum += A[r];
        } else {
            count += r - l + 1;
            sum -= A[l];
            l++;
            if (l > r) {
                r = l;
                if (r < N) sum += A[r];
            }
        }
    }

    cout << count << endl;

    return 0;
}