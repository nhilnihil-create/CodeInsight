#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

// N^P mod M（ただしM == -1の時はmodを取らない）
template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

int dp[100010]; //dp[i] = 石がi個の場合のgrundy数

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    for(int i = 0;i <= K;i++) {
        set<int> st;
        for(int j = 0;j < N;j++) {
            if(i >= vec.at(j)) {
                st.insert(dp[i - vec.at(j)]);
            }
        }
        int itr = -1;
        bool cnt = false;
        for(auto x:st) {
            if(x - itr != 1) {
                dp[i] = itr + 1;
                cnt = true;
                break;
            }
            itr = x;
        }
        if(cnt == false) {
            dp[i] = itr + 1;
        }
    }
    if(dp[K] == 0) {  
        cout << "Second" << endl;
    }
    else {
        cout << "First" << endl;
    }
}  