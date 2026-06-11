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

int main() {
    string S;
    cin >> S;
    bool ret = false;
    for(int i = 0;i < S.size() + 1;i++) {
        for(int j = i;j < S.size() + 1;j++) {
            if(i + S.size() - j == 7) {
                string A = S.substr(0,i);
                string B = S.substr(j,S.size() - j);
                A += B;
                if(A == "keyence") {
                    ret = true;
                }
            }
        }
    }
    if(ret == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}