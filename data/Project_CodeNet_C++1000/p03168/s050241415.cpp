// turmak-_-
#include<bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define nl "\n"
#define IOI return 0;
#define pb push_back
#define ll long long
#define ld long double
#define IOS ios_base :: sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define X first
#define Y second

using namespace std;
const int N = (int)2e5 + 7 ;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 + 7;
const int UNDEF = -1;

pii dx[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

double p[3001];
double dp[3001];
int main() {
    IOS
    //freopen("lepus.in", "r", stdin);
    //freopen("lepus.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>p[i];
    dp[0]=1.0;
    for(int i=1; i<=n; ++i) {
        for(int j=i; j>=0; --j) {
            dp[j]=dp[j-1]*p[i]+dp[j]*(1.0-p[i]);
        }
    }
    double ans = 0.0;
    for(int i=0; i<=n; ++i) {
        if(i>n-i) {
            ans+=dp[i];
        }
    }
    cout<<setprecision(9)<<fixed<<ans;
    IOI
}
