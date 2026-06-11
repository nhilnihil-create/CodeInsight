/** "Ever tried.
         Ever failed.
               No matter.
                   Try Again.
                        Fail again.
                             Fail better.**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define bp  __builtin_popcount
#define pb push_back
#define loop(i,n) for(int i = 0;i < int(n);i++)
#define sz(s) (int)(s.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define setdp memset(dp,-1,sizeof(dp))
#define db(x) cout<<" LOOK "<<(#x)<<" = "<<x <<'\n'
#define NumofDigits(n)   ((long long)log10(n)+1)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=1e5+5;
const  double EPS = 1e-9;
const int MOD = 1e9+7;
/*
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll fastpow(ll b, ll p)
{if(!p)return 1;ll ret = fastpow(b, p >> 1);ret *= ret;if(p&1)ret*= b;return ret;}
int dx[] = {- 1, 0, 0, 1, 0 };
int dy[] = { 0,- 1, 1, 0, 0 };*/
inline void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int n,m;
char arr[105][105];
bool valid(int i, int j)
{
    if(i>=0 && j>=0 && i<n && j<m)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   // File();
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int cnt=0;
            if(arr[i][j]=='#')
                continue;
            for(int d=0; d<8; d++)
            {
                int ni=i+dx[d];
                int nj=j+dy[d];
                if(valid(ni,nj))
                    if(arr[ni][nj]=='#')
                        cnt++;
            }
            arr[i][j]=char(cnt+'0');
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<arr[i][j];
        cout<<endl;
    }
}
