#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int X;
    cin >> X;
    int nax = 1;
    for (int b=1; b<=X; b++){
        for (int p=2; p<X; p++){
            if (pow(b,p) <= X)chmax(nax, (int)pow(b,p));
            else break;
        }
    }

    cout << nax << endl;
}