#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long
using namespace std;

int main() {
    string S; cin >> S; int ans=S.size();
    rep(i,S.size()){
        if(S[i]!=S[i+1]){
            ans=min(ans,max(i+1,(int)S.size()-i-1));
        }
    }
    cout << ans << endl;

    return 0;
}