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
    int N;
    cin >> N;
    vector<int> vec(N + 2);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i + 1);
    }
    vector<int> Sum1(N + 2);
    for(int i = 0;i < N;i++) {
        Sum1.at(i + 1) = Sum1.at(i) + abs(vec.at(i + 1) - vec.at(i));
    }
    vector<int> Sum2(N + 2);
    for(int i = N + 1;i >= 1;i--) {
        Sum2.at(i - 1) = Sum2.at(i) + abs(vec.at(i) - vec.at(i - 1));
    }
    for(int i = 1;i <= N;i++) {
        cout << Sum1.at(i - 1) + Sum2.at(i + 1) + abs(vec.at(i + 1) - vec.at(i - 1)) << endl; 
    }
}