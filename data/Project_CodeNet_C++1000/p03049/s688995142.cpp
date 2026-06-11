#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

ll solve(int N) {
    ll res = 0;
    ll a = 0, b = 0, both = 0;
    vector<string> A(N);
    rep(i,N) {
        string s; cin >> s;
        A.at(i) = s;
        int n = s.size();
        for (int j = 0; j < n-1; j++) {
            if (s[j] == 'A' && s[j+1] == 'B') res++, j++;
        }
        if (s[0] == 'B' && s[n-1] == 'A') both++;
        else if (s[0] == 'B') b++;
        else if (s[n-1] == 'A') a++;
    }
    if (a < b) {
        if (both >= b - a) a += b - a, both -= b - a;
        else a += both, both = 0;
    } else if (a > b) {
        if (both >= a - b) b += a - b, both -= a - b;
        else b += both, both = 0;
    }
    res += min(a,b);
    if (both >= 2) res += both / 2;
    return res;
}

ll solve2(int N) {
    vector<string> A(N);
    vector<int> a, b, ab;
    rep(i, N) {
        string S; cin >> S;
        A[i] = S;
        int e = S.size() - 1;
        if (S[0] == 'B' && S[e] == 'A') ab.push_back(i);
        else if (S[0] == 'B') b.push_back(i);
        else if (S[e] == 'A') a.push_back(i);
    }
    string T;
    set<int> used;
    if (a.size() > 0) {
        used.insert(a.back());
        T += A[a.back()]; a.pop_back();

    } 
    while (ab.size() > 0) {
        used.insert(ab.back());
        T += A[ab.back()]; ab.pop_back();
    }
    if (b.size() > 0) {
        used.insert(b.back());
        T += A[b.back()]; b.pop_back();
    }

    while (b.size() > 0 && a.size() > 0) {
        used.insert(a.back());
        used.insert(b.back());
        T += A[a.back()]; a.pop_back();
        T += A[b.back()]; b.pop_back();
    }

    rep(i,N) {
        if (used.count(i) == 0) T += A[i];
    }
    
    ll res = 0;
    for (int i = 0; i < T.size() - 1; i++) {
        if (T[i] == 'A' && T[i+1] == 'B') res++, i++;
    }
    return res;
}

int main() {
    int N; cin >> N;
    cout << solve2(N) << endl;
}
