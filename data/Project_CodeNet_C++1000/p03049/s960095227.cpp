#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    int headB = 0;
    int tailA = 0;
    int AB = 0;
    int other = 0;
    rep(i,N){
        if(S[i][0]=='B'&&S[i][S[i].size()-1]=='A') AB++;
        else if(S[i][0]=='B')headB++;
        else if(S[i][S[i].size()-1]=='A') tailA++;
        else other++;
    }
    int ans = 0;
    rep(i,N){
        rep(c,S[i].size()-1){
            if(S[i][c]=='A'&&S[i][c+1]=='B') ans++;
        }
    }
    if(AB==0){
        ans+=min(headB,tailA);
    }else{
        if(headB==0&&tailA==0) ans+=AB-1;
        else ans += AB+min(headB,tailA);
    }
    cout << ans << endl;
    return 0;
}