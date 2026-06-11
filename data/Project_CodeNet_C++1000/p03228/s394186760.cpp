#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000007;
const double pi = acos(-1);

int main() {
    ll A,B; cin >> A >> B;
    int K; cin >> K;
    REP(i,K) {
        if(i%2 == 0) {
            if(A%2 == 0) {
                B += A/2;
                A /= 2;
            } else {
                B += A/2;
                A--;
                A /= 2;
            }
        } else {
            if(B%2 == 0) {
                A += B/2;
                B /= 2;
            } else {
                A += B/2;
                B--;
                B /= 2;
            }
        }
    }
    cout << A << " " << B << endl;
}