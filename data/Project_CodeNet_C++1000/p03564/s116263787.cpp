#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N, K;
    cin >> N >> K;
    int tmp = 1;
    rep(i, N) {
        if (tmp + K < tmp * 2) tmp += K;
        else tmp *= 2;
    }
    cout << tmp << endl;



    return 0;
}
