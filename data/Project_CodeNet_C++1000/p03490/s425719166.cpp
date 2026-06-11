#include <bits/stdc++.h>

#define bug(x) cout << #x << " = " << x << endl;
#define fr(a) freopen(a,"r",stdin);
#define fw(a) freopen(a,"w",stdout);
#define tc() int tc;cin >> tc; for (int _tc=1;_tc<=tc;_tc++)
#define up(i,l,r) for (int i=l;i<=r;i++)
#define down(i,r,l) for (int i=r;i>=l;i--)
#define rep(i,l,r) for (int i=l;i<r;i++)
#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> ii;

/****************************************************/
void printArr(int a[], int l, int r)
{
    up(i,l,r) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printMtx(int a[][1010],int n, int m)
{
    up(i,1,n) {
        up(j,1,m) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
/****************************************************/

bool check = true;
string s;
ll x,y, dp[2][16010],cnt, curDir;
vector<ll> v[2];

int main()
{
    ios_base::sync_with_stdio(0);

   // fr("test.in");
    cin >> s;
    cin >> x >> y;

    x+=8000;
    y+=8000;
    curDir = 0;
    rep(i,0,s.length()) {
        if (s[i] == 'T') {
            if (cnt!= 0) v[curDir].pb(cnt);
            curDir = 1-curDir;
            cnt = 0;
        }
        else cnt++;
    }
    if (cnt!=0) v[curDir].pb(cnt);

    memset(dp,false,sizeof(dp));
    dp[1][8000] = true;
    rep(i,0,v[0].size()) {
        up(j,0,16000) {
            dp[i%2][j] = false;
            if (i == 0 && s[0] == 'F') {
                if (j - v[0][i] >= 0 && dp[1-i%2][j-v[0][i]]) dp[i%2][j] = true;
            }
            else {
                if (j - v[0][i] >= 0 && dp[1-i%2][j-v[0][i]]) dp[i%2][j] = true;
                if (j + v[0][i] <= 16000 && dp[1-i%2][j+v[0][i]]) dp[i%2][j] = true;
            }
        }
    }
    if (v[0].size() > 0) check &= dp[(v[0].size()-1)%2][x];
    else {
        if (x!=8000) check = false;
    }

    memset(dp,false,sizeof(dp));
    dp[1][8000] = true;
    rep(i,0,v[1].size()) {
        up(j,0,16000) {
            dp[i%2][j] = false;
            if (j - v[1][i] >= 0 && dp[1-i%2][j-v[1][i]]) dp[i%2][j] = true;
            if (j + v[1][i] <= 16000 && dp[1-i%2][j+v[1][i]]) dp[i%2][j] = true;
        }
    }
    if (v[1].size() > 0) check &= dp[(v[1].size()-1)%2][y];
    else {
        if (y!=8000) check = false;
    }
    if (check) cout << "Yes\n";
    else cout << "No\n";
}
