/**Bismillahir Rahmanir Raheem
    Author:Refatul Fahad**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define sz(s)  (int)s.size()
#define all(s)  s.begin(),s.end()
const int N = 1e6 + 5;
const ll M = (ll)1e9 + 7;
const double pi=2*acos(0.0);
const double esp=1e-9;
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
int reset(int N,int pos) {
    return N= N & ~(1<<pos);
}
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}

int dx[]= {0,1,-1};
int dy[]= {1,0,0};
string s[1005];

ll dp[1005][1005],n,m;
//ll fun(int i,int j) {
//    if(i>=n||j>=m)return 0;
//    if(s[i][j]=='#')return 0;
//    if(i==n-1&&j==m-1)return 1ll;
//    if(dp[i][j]!=0)return dp[i][j];
//    ll r1=0ll,r2=0ll;
//    if(i+1<n) {
//        r1=fun(i+1,j);
//    }
//    if(j+1<m) {
//        r2=fun(i,j+1);
//    }
//    return dp[i][j]=(r1+r2)%M;
//}
int main() {

    //IOS;
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test=1;
    //cin>>test;
    for(int cs=1; cs<=test; ++cs) {

        cin>>n>>m;
        for(int i=0; i<n; ++i) {
            cin>>s[i];
        }
        dp[0][0]=1;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(s[i][j]=='#')continue;
                if(i+1<n) {
                    if(s[i+1][j]=='.')
                        dp[i+1][j]=(dp[i+1][j]+dp[i][j])%M;
                }
                if(j+1<m) {
                    if(s[i][j+1]=='.')
                        dp[i][j+1]=(dp[i][j+1]+dp[i][j])%M;
                }
            }
        }
        cout<<dp[n-1][m-1]<<endl;
    }
    return 0;
}

