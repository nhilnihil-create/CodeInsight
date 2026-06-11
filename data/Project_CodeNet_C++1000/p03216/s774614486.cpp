#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#define int long long
template<class T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return 1; } return 0; }

int N;
string S;
long long M, C, P;

void add (int i) {
    if (S[i] == 'M') M++;
    else if (S[i] == 'C') { C++; P += M; }
}

void erase (int i) {
    if (S[i] == 'M') { M--; P -= C; }
    else if (S[i] == 'C') C--;
}

long long solve(int K) {
    long long ans = 0;
    M = 0, C = 0, P = 0;
    int left = 0;
    for (int right = 0; right < N;) {
        while (left < N && abs(right-left) < K) add(left++);
        if (S[right] == 'D') ans += P;
        erase(right++);
    }
    return ans;
}

int main() {
    int Q;
    cin >> N >> S >> Q;
    for (int i = 0; i < Q; i++) {
        int k; cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}