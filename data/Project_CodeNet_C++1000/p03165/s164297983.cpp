#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define pb push_back
#define MOD 1000000007
#define sz5 100005
#define sz6 1000005
#define UP upper_bound
#define LB lower_bound
#define F first
#define S second
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>

int main() {
    FAST
    string a, b;
    cin>>a>>b;
    int n=a.length(), m=b.length();
    int dp[n+4][m+4], la, lb;
    memset(dp, 0, sizeof(dp));

    for(la=1;la<=n;la++){
        for(lb=1;lb<=m;lb++){
            dp[la][lb]=max(dp[la][lb-1], dp[la-1][lb]);
            if(a[la-1]==b[lb-1])
                dp[la][lb]=max(dp[la][lb], 1+dp[la-1][lb-1]);
        }
    }

    string ans;
    int x=n, y=m;
    while(dp[x][y]!=0){
        if(dp[x][y]==dp[x-1][y])
            x--;
        else
        if(dp[x][y]==dp[x][y-1])
            y--;
        else{
            ans.pb(a[x-1]);
            x--;    y--;
        }
    }

    reverse(ALL(ans));
    cout<<ans<<endl;

    return 0;
}