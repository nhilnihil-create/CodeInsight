#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin>> S;
    int N=S.length();
    int ans=N;
    rep(i,0,N-1){
        if (S[i]!=S[i+1]){
            ans=min(max(i+1, N-i-1), ans);
        }
    }
   cout << ans<<"\n";
}