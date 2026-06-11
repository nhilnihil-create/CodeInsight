#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    string S;
    cin >> S;
    int ans = S.size();
    for(int i = 0; i < S.size()-1; i++) {
        if(S[i] != S[i+1]) {
            ans = min(ans,max(i+1,(int)S.size()-i-1));
        }
    }
    cout << ans << endl;
}