//I solved it before. If I had enough time I wouldn't have submitted old codes.
//If you forbid I won't do this in the upcoming contests
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <bits/stdc++.h>
#define fw(x) freopen("x.txt","w",stdout)
#define For(i,a,b,c) for(int i = a;i < b;i+=c)
#define REP(i,n) for(int i = 0;i < n;++i)
#define REP1(i,n) for(int i = 1; i<=n;i++)
#define mem(a,s) memset(a,s,sizeof a)
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
#define pf printf
#define sc scanf
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define vii vector<int>
#define vll vector<ll>
#define vss vector<string>
#define debug(x)  cout<<#x"="<<(x)<<endl
#define pb push_back


using namespace std;


// moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/


//big_mod

//ll bigmod(ll a,ll b,ll m)
//{if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a)% m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
//ll setBit1(ll num, int idx) {return num or (1ll<<idx);}
//ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
//ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
string s, t;
int c[3001][3001];
int b[3001][3001];
void lcs(int i, int j){
    if(i<=0 || j<=0) return;
    if(b[i][j] != 0) return;
    if(s[i]==t[j]){
        lcs(i-1, j-1);
        c[i][j] = 1 + c[i-1][j-1];
        b[i][j] = 3;
    }
    else {
        lcs(i-1, j);
        lcs(i, j-1);
        if(c[i-1][j] > c[i][j-1]){
            c[i][j] = c[i-1][j];
            b[i][j] = 1;
        }
        else{
            c[i][j] = c[i][j-1];
            b[i][j] = 2;
        }
    }
}
int main()
{
    fast;
    cin>>s>>t;
    s = 'd' + s;
    t = 'x' + t;
    int sz1 = s.size()-1;
    int sz2 = t.size()-1;
    REP1(i, sz1) c[0][i] = 0;
    REP1(i, sz2) c[i][0] = 0;
    c[0][0] = 0;
    lcs(sz1, sz2);
    string ans = "";
    while(sz1>0&&sz2>0){
        if(b[sz1][sz2]==3){
            ans = s[sz1] + ans;
            sz1--;
            sz2--;
        }
        else if(b[sz1][sz2]==1){
            sz1--;
        }
        else sz2--;
    }
    cout<<ans<<'\n';
    return 0;
}