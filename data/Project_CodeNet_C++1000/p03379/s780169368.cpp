#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<int> X(N),Y;
    REP(i,N){
        cin >> X[i];
    }
    
    Y = X;
    sort(X.begin(),X.end());
    
    int midm, midp;
    midm = X[N/2-1];
    midp = X[N/2];
    
    REP(i,N){
        if ( Y[i] < midp ){
            cout << midp << endl;
        } else {
            cout << midm << endl;
        }
    }
    
    
    
    return 0;
}
