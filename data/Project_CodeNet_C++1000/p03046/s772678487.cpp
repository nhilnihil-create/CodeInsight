#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int Pow(int a) {
    ll ret = 1;
    for(int i = 0;i < a;i++) {
        ret *= 2;
    }
    return ret;
}

int main() {
    int N,K;
    cin >> N >> K;
    if(N == 1) {
        if(K == 0) {
            cout << "0 0 1 1" << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    else if(K > Pow(N) - 1) {
        cout << -1 << endl;
    }
    else {
        for(int i = Pow(N) - 1;i >= 0;i--) {
            if(i != K) {
                cout << i << " ";
            }
        }
        cout << K << " ";
        for(int i = 0;i <= Pow(N) - 1;i++) {
            if(i != K) {
                cout << i << " ";
            }
        }
        cout << K << endl;
    }
}