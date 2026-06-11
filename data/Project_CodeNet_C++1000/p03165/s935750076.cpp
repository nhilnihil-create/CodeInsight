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

int dp[4000][4000];
pii  p[4000][4000];
int main() {
    IOS
    //freopen("lepus.in", "r", stdin);
    //freopen("lepus.out", "w", stdout);
    string a,b;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    a = ' '+a;
    b = ' '+b;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(a[i]==b[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
                p[i][j]={i-1,j-1};
            } else {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                if(dp[i][j-1]>dp[i-1][j]) {
                    p[i][j]={i,j-1};
                } else {
                    p[i][j]={i-1,j};
                }
            }
        }
    }
    pii cur = {n,m};
    string s;
    while(true) {
        if(a[cur.X]==b[cur.Y]) s = a[cur.X]+s;
        if(cur.X<=1 && cur.Y<=1) {break;}
        pii Next = p[cur.X][cur.Y];
        cur.X = Next.X,cur.Y=Next.Y;
    }
    cout<<s;
    IOI
}
