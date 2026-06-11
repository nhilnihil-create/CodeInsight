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
*/

void solve() {
    string s,t,res;
    cin >> s >> t;
    int n = s.length(),m = t.length();
    int dp[n][m];
    ms(dp);
    rep(i,n) {
        rep(j,m) {
            if (s[i] == t[j]) dp[i][j] = (i>0 && j>0 ? dp[i-1][j-1]:0) + 1;
            else dp[i][j] = max(i>0?dp[i-1][j]:0,j>0?dp[i][j-1]:0);
        }
    }
    int i=n-1,j=m-1;
    // rep(i,n) {deba(dp[i]); cout << endl;}
    while (i>=0 && j>=0) {
        if (s[i] == t[j]) {
            res.push_back(s[i]);
            i--; j--;
        }else {
            if (i == 0 || j ==0) {
                if (i == 0) j--;
                else i--;
            }else {
                if (dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
            }
            
        }
    }
    reverse(all(res));
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    FastOpen
    int t; t=1;
    while (t--) solve();
}



