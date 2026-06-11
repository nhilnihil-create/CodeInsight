#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    map<int64_t, int64_t>d;
    for (int i=0; i<N; i++) {
        int64_t n;
        cin >> n;
        if(d.count(n) > 0) {
            d[n] = d[n] + 1;
        } else {
            d[n] = 1;
        }
    }

    int64_t M;
    cin >> M;
    bool ok = true;
    for (int i=0; i<M; i++) {
        int n;
        cin >> n;
        if (d.count(n) == 0) {
            ok = false;
            break;
        } else {
            d[n] -= 1;
            if (d[n] < 0) {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}