#include <bits/stdc++.h>
using namespace std;

string rotation ( string S ){
    int N = S.size();
    char last = S[0];
    for ( int i = 0; i < N-1; ++i){
        S[i] = S[i+1];
    }
    S[N-1] = last;
    return S;
}

int main() {
    string S,T;
    cin >> S >> T;
    bool flg = false;
    int N = S.size();
    for ( int i = 0; i < 2*N; ++i){
        S = rotation(S);
        if ( S == T ) flg = true;
    }
    
    if ( flg ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}