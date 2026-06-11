#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    veci A(N),B(M);
    REP(i,N) cin >> A[i];
    REP(i,M) cin >> B[i];
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end());
    for(int i = X+1; i <= Y; i++) {
        if(A[0] < i && i <= B[0]) {
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
}
