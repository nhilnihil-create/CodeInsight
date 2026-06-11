#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a < b) swap(a,b);
    if (b == 0) return a;
    return a%b == 0 ? b : gcd(b, a%b);
}
int lcm(int a, int b) { return a*b/gcd(a,b);}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    vector<int> left(N+1);
    vector<int> right(N+1);
    left[0] = A[0];
    for (int i=0;i<N;i++){
        left[i+1] = gcd(left[i],A[i]);
    }
    right[N] = A[N-1];
    for (int i=N;i>=1;i--){
        right[i-1] = gcd(right[i],A[i-1]);
    }
    int ans = -1;
    for (int i=0;i<N;i++){
        int res;
        if (i==0){
            res = right[i+1];
        } else if (i==N-1){
            res = left[i];
        } else {
            res = gcd(left[i],right[i+1]);
        }
        if (ans < res) ans = res;
    }
    cout << ans << "\n";
}