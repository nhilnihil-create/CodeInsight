#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

int N, M;

int main(void) {
    map<int,int> D;

    cin >> N;
    rep(i, N) {
        int n;
        cin >> n;
        D[n]++;
    }

    cin >> M;
    bool result = true;
    rep(i, M) {
        int n;
        cin >> n;
        if (D[n] == 0) {
            result = false;
            break;
        }
        D[n]--;
    }

    if (result) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    

    return 0;
}