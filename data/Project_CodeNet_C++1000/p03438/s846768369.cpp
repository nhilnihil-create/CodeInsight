#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int n; cin >> n;
    ll count_p = 0;
    ll count_m = 0;
    vector<int> A(n), B(n);
    rp(i, 0, n){
        scanf("%d", &A[i]);
    }
    rp(i, 0, n){
        scanf("%d", &B[i]);
    }
    rp(i, 0, n){
        int a = A[i];
        int b = B[i];
        int c = a - b;
        if(c > 0) count_m += c;
        if(c < 0) {
            c = -c;
            count_p += c/2;
        }
    }
    if(count_p >= count_m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}