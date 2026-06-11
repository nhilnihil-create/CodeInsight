#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int DFS(int n, int t) {
    int tmp = 100000;
    if (t<=5) {
        rep(i, 9) {
            int nxt = n-i*(pow(9, 6-t));
            if (nxt<0) continue;
            tmp = min(tmp, DFS(nxt, t+1)+i);
        }
        return tmp;
    }
    else if (t<=11) {
        rep(i, 6) {
            int nxt = n-i*pow(6, 12-t);
            if (nxt<0) continue;
            tmp = min(tmp, DFS(nxt, t+1)+i);
        }
        return tmp;
    }
    else {
        if (n<6) return n;
        else return 100000;
    }
}

int main() {
    int n;
    cin >> n;
    cout << DFS(n, 1) << endl;
}