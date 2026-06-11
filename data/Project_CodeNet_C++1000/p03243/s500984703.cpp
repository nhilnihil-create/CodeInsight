#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    for (int i=N; i<pow(10,9); i++){
        string s = to_string(i);
        char s0 = s.at(0);
        bool ans = true;
        for (int j=0; j<3; j++){
            if (s0 != s[j]){
                ans = false;
            }
        }

        if (ans){
            cout << i << endl;
            return 0;
        }
    }
}