#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

int main() {
    int H,W,N;
    cin >> H >> W >> N;
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    string S,T;
    cin >> S >> T;
    bool ret = true;
    int left = 0;
    int right = W;
    if(S.at(N - 1) == 'L') {
        left++;
    }
    else if(S.at(N - 1) == 'R') {
        right--;
    }
    for(int i = N - 2;i >= 0;i--) {
        if(T.at(i) == 'L') {
            right = min(W,right + 1);
        }
        else if(T.at(i) == 'R') {
            left = max(0,left - 1);
        }
        if(S.at(i) == 'L') {
            left++;
        }
        else if(S.at(i) == 'R') {
            right--;
        }
        if(left >= right) {
            ret = false;
        }
    }
    if(b < left || right <= b) {
        ret = false;
    }
    left = 0;
    right = H;
    if(S.at(N - 1) == 'U') {
        left++;
    }
    else if(S.at(N - 1) == 'D') {
        right--;
    }
    for(int i = N - 2;i >= 0;i--) {
        if(T.at(i) == 'U') {
            right = min(H,right + 1);
        }
        else if(T.at(i) == 'D') {
            left = max(0,left - 1);
        }
        if(S.at(i) == 'U') {
            left++;
        }
        else if(S.at(i) == 'D') {
            right--;
        }
        if(left >= right) {
            ret = false;
        }
    }
    if(a < left || right <= a) {
        ret = false;
    }

    if(ret == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}