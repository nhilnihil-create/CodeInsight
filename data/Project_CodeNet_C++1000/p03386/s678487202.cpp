#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    map<int,bool>isouted;

    int a, b, k;
    cin >> a >> b >> k;
    for (int i=a; i<=min(a+k-1,b); i++){
        isouted[i] = true;
        cout << i << endl;
    }

    for (int i=max(b-k+1,a); i <= b; i++){
        if (isouted[i])continue;
        else cout << i << endl;
    }
}