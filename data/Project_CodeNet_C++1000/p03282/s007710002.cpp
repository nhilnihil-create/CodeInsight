#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    int64_t K;
    cin >> S;
    cin >> K;
    
    int64_t ini = 300;
    int64_t ini_num = -1;
    for ( int64_t i = 0; i < S.size(); ++i){
        if ( S[i] != '1' ){
            ini = i;
            ini_num = S[i] - '0';
            break;
        }
    }
    
    if ( K >= ini + 1 ){
        cout << ini_num << endl;
    } else {
        cout << S[K-1] << endl;
    }
    
    return 0;
}
