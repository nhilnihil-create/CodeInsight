#include <bits/stdc++.h>
using namespace std;

int main() {
    string S,T;
    cin >> S >> T;
    
    int N = S.size();
    
    map<int,int> m;
    bool flg = true;
    for ( int i = 0; i < N; ++i){
        int s = S[i] - 'a';
        int t = T[i] - 'a';
        ++s; ++t;
        if ( m[s] == 0 ){
            m[s] = t;
        } else {
            int u = m[s];
            if ( u != t ) flg = false;
        }
    }
    
    vector<int> c(27,0);
    for ( int i = 1; i <= 26; ++i){
        int x = m[i];
        if ( x == 0 ) continue;
        c[x] = c[x] + 1;
        //cout << "c[" << x << "] = " << c[x] << endl;
        if ( c[x] > 1 ) flg = false;
    }
    
    if ( flg ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
