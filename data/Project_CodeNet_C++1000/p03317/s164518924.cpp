#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, K;
    cin >> N >> K;
    N--; K--;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int ans = N / K + (N%K!=0);
    cout << ans << endl;
    return 0;
}