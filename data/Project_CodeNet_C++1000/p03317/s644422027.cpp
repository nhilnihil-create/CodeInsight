#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, 0, N) cin >> A.at(i);
    cout << (N + K - 3) / (K - 1) << endl;
}