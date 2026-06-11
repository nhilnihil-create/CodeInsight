#include <bits/stdc++.h>

using namespace std;


int main() {
    int ans = 0;
    int N, M, X;
    cin >> N >> M >> X;
    for(int i = 0 ; i < M ; i++){
        int a;
        cin >> a;
        if( a > X ){
            ans++;
        }
    }
    cout << min(ans, M - ans) << endl;
}
