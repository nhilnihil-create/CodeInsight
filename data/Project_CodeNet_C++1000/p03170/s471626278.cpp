#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define repd(i, a) for (int i = (a)-1; i >= 0; i--)
#define reps(i, a, j) for (int i = (j); i < (a); i++)
#define deb(x) cout << #x << " " << x << endl;
#define debs(x) cout << #x << " " << x << " ";
#define deba(x) for (auto _i:x) cout << _i << " "; cout << endl;
#define ms(a) memset(a,0,sizeof(a));
#define mp make_pair
#define eb emplace_back
#define FastOpen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pii pair < int , int >
#define all(a) a.begin(),a.end() 
//int power(int x,int p){if(p==0)return 1;if(p==1)return x;if(p%2)return x*power(x,p-1);int y=power(x,p/2);return y*y;}
/*
k stones 
moves - 
0 - losing state

*/

void solve() {
    int n,k; cin >> n >> k;
    int moves[n]; rep(i,n) cin >> moves[i];
    int dp[k+1];
    ms(dp);
    dp[0] = 0; // losing state
    reps(i,k+1,1) {
        rep(j,n) {
            if (i-moves[j] >= 0) {
                if (dp[i-moves[j]] == 0) dp[i] = 1;
            }
        }
    }
    if (dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    FastOpen
    int t; t=1;
    while (t--) solve();
}



