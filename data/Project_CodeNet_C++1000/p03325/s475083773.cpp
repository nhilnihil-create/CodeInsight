#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    int ans = 0;
    rep(i, N){
        cin >> a[i];
        while(a[i] % 2 == 0){
            ans++;
            a[i] /= 2;
        }
    }

    cout << ans << endl;


    return 0;
}