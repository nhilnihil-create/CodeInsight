#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
/// khodaya komak kon
/// ya navid navid
/// ye tec khaphan ke yadam bemone : age jayi didi soale masir hamiltoni mikhad rasasho bokon yal oilery;https://mobomovie1.top/series/%D8%AF%D8%A7%D9%86%D9%84%D9%88%D8%AF-%D8%B3%D8%B1%DB%8C%D8%A7%D9%84-%D9%81%D8%B1%DB%8C%D9%86%D8%AC-fringe-2008-2013-%D8%A8%D8%A7-%D8%B2%D9%8A%D8%B1%D9%86%D9%88%D9%8A%D8%B3-%D9%81%D8%A7%D8%B1/
/// age ye ja mikhasti to dp az ozv i k ta entekhab koni bejash ye log bezan (nominal) hamoon 2**k va o 1 ent kon
const int N=302;
ll dp[N][N][N];
ll par[N][N][2];
int32_t main(){
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n=s.size();
    for (int i=0;i<n;i++){
        for (int j=0;j<N;j++){
            dp[i][i+1][j]=1;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=i+2;j<=n;j++){
            for (int l=i;l<j;l++){
                if (s[l]==s[j-1]){
                    par[i][j][1]=l;
                    break;
                }

            }
            for (int l=j-1;l>=i;l--){
                if (s[l]==s[i]){
                    par[i][j][0]=l;
                    break;
                }
            }
        }
    }
    for (int i=n-1;i>-1;i--){
        for (int j=i+2;j<=n;j++){
            for (int l=0;l<=k;l++){
                dp[i][j][l]=max(dp[i+1][j][l],dp[i][j-1][l]);
                if (l>0){
                    dp[i][j][l]=max(dp[i][j][l],2+dp[i+1][j-1][l-1]);
                }
                ll p=par[i][j][0];
                if (p!=i){
                    dp[i][j][l]=max(dp[i][j][l],2+dp[i+1][p][l]);
                }
                p=par[i][j][1];
                if (p!=j-1){
                    dp[i][j][l]=max(dp[i][j][l],2+dp[p+1][j-1][l]);
                }
                //cout << i << " " << j << " " << l << " " << dp[i][j][l]  << endl;


            }

        }
    }
    //cout << 3 << endl;
    cout << dp[0][n][k] << endl;
}
