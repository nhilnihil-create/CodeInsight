#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)
int main(){
    string S; cin >> S;
    int N = S.size();

    int ans = N;
    rep(i, 0, N-1){
        if(S[i] !=  S[i+1]){
            ans = min(ans, max(i + 1, N - 1 - i));
        }
    }
    cout << ans << endl;
}