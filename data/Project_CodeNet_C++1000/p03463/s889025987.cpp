#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int turn = 1;
    while (1) {
        if (turn) {
            if (++A == B) {
                cout << "Borys" << endl;
                return 0;
            }
        }
        else {
            if (--B == A) {
                cout << "Alice" << endl;
                return 0;
            }
        }
        turn = (turn + 1) % 2;
    }
    return 0;
}