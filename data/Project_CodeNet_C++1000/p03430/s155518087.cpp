#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define taskname "A"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 3e2 + 5;
const int maxm = 1e7 + 5;

const int mod = 1e9 + 7;
string s;

int n , k , dp[maxn][maxn][maxn];
int cal(int l , int r , int k){
    if(l > r)return 0;
    if(l == r)return 1;
    int & res = dp[l][r][k];
    if(res != -1)return res;
    res = 0;
    res = max(cal(l+1,r,k),cal(l,r-1,k));
    if(s[l]==s[r])res = max(res,cal(l+1,r-1,k)+2);
    if(k > 0)res = max(res,cal(l+1,r-1,k-1)+2);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP" , "r"))
        freopen(taskname".INP","r",stdin),
        freopen(taskname".OUT","w",stdout);
    cin >> s >> k;memset(dp,-1,sizeof dp);
    cout << cal(0,(int)s.size()-1,k);
}
