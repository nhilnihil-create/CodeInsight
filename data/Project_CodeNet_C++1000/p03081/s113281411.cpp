#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2100000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<char,char> P;
typedef pair<int,P> PP;

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void mod(ll &val, ll M) {
    val = val % M;
    if(val < 0) {
        val += M;
    }
}

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

int N,Q;
string S;
vector<P> vec;

int solve(int a) {
    for(int i = 0;i < Q;i++) {
        if(vec.at(i).first == S.at(a)) {
            if(vec.at(i).second == 'L') {
                a--;
            }
            else {
                a++;
            }
        }
    }
    return a;
}

int main() {
    cin >> N >> Q;
    vec.assign(Q,P(0,0));
    cin >> S;
    S.insert(S.begin(),'a');
    S += 'a';
    for(int i = 0;i < Q;i++) {
        cin >> vec.at(i).first >> vec.at(i).second;
    }
    int ret1,ret2;
    int left = 0;
    int right = N + 2;
    int mid;
    while(right - left > 1) {
        mid = (left + right) / 2;
        if(solve(mid) == 0) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    ret1 = left;
    left = 0;
    right = N + 2;
    while(right - left > 1) {
        mid = (left + right) / 2;
        if(solve(mid) == N + 1) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    ret2 = right;
    cout << ret2 - ret1 - 1 << endl;
}