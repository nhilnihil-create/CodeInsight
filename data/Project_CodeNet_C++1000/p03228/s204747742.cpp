#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1000000000;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    for (int i=0; i<K; i++){
        if (i%2 == 0){
            //Takahasi's turn;
            if (A%2){
                A--;
            }
            B += A/2;
            A -= A/2;
        }
        else {
            // Aoki's turn;
            if (B%2)B--;
            A += B/2;
            B -= B/2;
        }
    }
    cout << A << " " << B << endl;
}