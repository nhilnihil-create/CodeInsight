#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int N = S.size();
    
    int count = 0;
    for ( int i = 0; i < N; ++i){
        count = count + ( S[i] - '0' );
    }
    
    int ans1 = count * 2;
    int ans2 = ( N - count ) * 2;
    
    cout << min(ans1,ans2) << endl;
    
    return 0;
}