#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i,N) {
        cin >> P[i];
        P[i]--;
    }

    map<int,int> f;
    rep(i,N) f[P[i]] = i;

    vector<int> rev;

    rep(i,N-1) {
        if (f[i] > f[i+1]) rev.push_back(i);
    }

    if (rev.size() >= 1) {
        int MAX = 0;
        rep(i,rev.size()-1) MAX = max(MAX, rev[i+1]-rev[i]);
        MAX = max(MAX, rev[0] + 1);
        MAX = max(MAX, N-1-rev[rev.size()-1]);

        cout << N - MAX << endl;
    }
    else cout << 0 << endl;
}
