#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    cout << (N-2)/(K-1)+1 << endl;
    return 0;
}
