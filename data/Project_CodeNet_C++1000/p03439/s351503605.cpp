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

bool question(int n) {
    cout << n << endl;
    fflush(stdout);
    string seat;
    cin >> seat;
    if (seat == "Vacant") {
        fflush(stdout);
        exit(0);
    }
    else {
        return (seat == "Male");
    }
}
int main()
{
    int N;
    cin >> N;

    int left = 0, right = N - 1;
    bool head = question(left);
    bool tail = question(right);

    rep(i, 18) {
        int mid = (left + right) / 2;
        bool center = question(mid);
        if ((mid - left) % 2 && center == head || (mid - left) % 2 == 0 && center != head) {
            right = mid;
            tail = center;
        }
        else {
            left = mid;
            head = center;
        }
    }
}