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

int dp[1001][1001];
const int m = 1e9+7;

int32_t main()
{
   // shuru_krte_hai_bina_kisi_bakchodi_ke();
    int h,w;
    cin>>h>>w;
    string s[h];
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    for(int i=0;i<h;i++){
        if(s[i][0]=='.'){
            dp[i][0] = 1;
        }else{
            break;
        }
    }
    for(int i=0;i<w;i++){
        if(s[0][i]=='.'){
            dp[0][i] = 1;
        }else{
            break;
        }
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(s[i][j]=='.'){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%m;
            }
        }
    }
    cout<<dp[h-1][w-1];
    return 0;
}