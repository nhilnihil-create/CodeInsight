/* To Kaise Hain Aaplog*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) (x).begin(), (x).end()

void shuru_krte_hai_bina_kisi_bakchodi_ke()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}



int32_t main()
{
    //shuru_krte_hai_bina_kisi_bakchodi_ke();
    string s,t;
    cin>>s>>t;
    int n = s.length()+1;
    int m = t.length()+1;

    int dp[n][m]={0};
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<m;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(t[j-1]==s[i-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans="";
    int len = dp[n-1][m-1];
    int i = n-1,j=m-1;
    while(dp[i][j]>0){
        if(dp[i][j]!=dp[i-1][j] && dp[i][j]!=dp[i][j-1]){
            ans+=s[i-1];
            i--;
            j--;
        }else if(dp[i][j]==dp[i-1][j]){
            i--;
        }else{
            j--;
        }
    }
    reverse(all(ans));
    cout<<ans;
    return 0;
}