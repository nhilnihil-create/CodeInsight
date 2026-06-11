#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    
    
    // 0101 で塗る場合
    int ans = 0;
    for ( int i = 0; i < N; ++i){
        int c = S[i] - '0';
        int c2 = i % 2;
        if ( c != c2 ) ++ans;
    }
    
    int ans2 = 0;
    for ( int i = 0; i < N; ++i){
        int c = S[i] - '0';
        int c2 = (i+1) % 2;
        if ( c != c2 ) ++ans2;
    }
    
    cout << min(ans,ans2) << endl;
    
    return 0;
}
