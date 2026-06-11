#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main() {
    int N;
    cin >> N;
    double balance;
    for (int i=0; i<N; i++){
        double x;
        string u;
        cin >> x >> u;

        if (u=="BTC"){
            balance += x*380000.0;
        }
        else balance += x;
    }
    cout << balance << endl;
}