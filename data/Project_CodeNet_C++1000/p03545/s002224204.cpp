#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string S;
    cin >> S;
    
    int A = S[0] - '0', B = S[1] - '0', C = S[2] - '0', D = S[3] - '0';
    
    if ( A + B + C + D == 7 ){
        cout << A << "+" << B << "+" << C << "+" << D << "=" << 7 << endl;
        return 0;
    } else if ( A + B + C - D == 7 ) {
        cout << A << "+" << B << "+" << C << "-" << D << "=" << 7 << endl;
        return 0;
    } else if ( A + B - C + D == 7 ) {
        cout << A << "+" << B << "-" << C << "+" << D << "=" << 7 << endl;
        return 0;
    } else if ( A - B + C + D == 7 ) {
        cout << A << "-" << B << "+" << C << "+" << D << "=" << 7 << endl;
        return 0;
    } else if ( A + B - C - D == 7 ) {
        cout << A << "+" << B << "-" << C << "-" << D << "=" << 7 << endl;
        return 0;
    } else if ( A - B + C - D == 7 ) {
        cout << A << "-" << B << "+" << C << "-" << D << "=" << 7 << endl;
        return 0;
    } else if ( A - B - C + D == 7 ) {
        cout << A << "-" << B << "-" << C << "+" << D << "=" << 7 << endl;
        return 0;
    } else if ( A - B - C - D == 7 ) {
        cout << A << "-" << B << "-" << C << "-" << D << "=" << 7 << endl;
        return 0;
    }
    
    return 0;
}