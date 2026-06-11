#include <bits/stdc++.h>
using namespace std;
using vi   = vector<int>;
using vll  = vector<long long>;
using vvi  = vector<vi>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;

int main() {
    int N; cin >> N;
    int ans = 0;

    for(int i = 1; i <= N; i=i+2) {
        int tmp = 0, sqrt_i = sqrt(i);
        if(sqrt_i*sqrt_i == i) continue;
        for(int j = 2; j <= sqrt_i; j++) {
            if (i%j==0) tmp++;
            if (tmp > 3) break;
        }
        if(tmp == 3) ans++;

    }
    cout << ans << endl;
}