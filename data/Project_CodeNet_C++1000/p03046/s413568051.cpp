#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000001;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int M,K;
    cin >> M >> K;
    if(M == 0) {
        if(K == 0) {
            cout << 0 << " " << 0 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    else if(M == 1) {
        if(K == 0) {
            cout << "0 1 1 0" << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    else {
        M = pow(2,M) - 1;
        if(M < K) {
            cout << -1 << endl;
        }
        else {
            for(int i = M;i >= 0;i--) {
                if(i != K) {
                    cout << i << " ";
                }
            }
            cout << K << " ";
            for(int i = 0;i <= M;i++) {
                if(i != K) {
                    cout << i << " ";
                }
            }
            cout << K << endl;
        }
    }
}