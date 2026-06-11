#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int cnt = 0;
    for (int i=0; i<= A; i++){
        for (int j=0; j<= B; j++){
            for (int k=0; k<=C; k++){
                if (500*i + 100*j + 50*k == X){
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}