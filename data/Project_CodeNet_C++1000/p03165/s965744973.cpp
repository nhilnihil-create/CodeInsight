#include <bits/stdc++.h>
#define ll long long 
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define setbit(x,k) (x |= (1 << k))
#define clearbit(x,k) (x &= ~(1ll << k))
#define checkbit(x,k) (x & (1ll << k))
#define mp make_pair
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int,int> 
#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define yes printf("yes\n")
#define NO printf("NO\n")
#define No printf("No\n")
#define no printf("no\n")
#define nn printf("\n") 
#define mod 10000007
using namespace std;

string s,t,res=""; int ls, lt;
int ans[3003][3003];
int dp[3003][3003];

int solve(int p1, int p2)
{
    if(p1 >= ls || p2 >= lt) return 0; 
    if(dp[p1][p2]!=-1) return dp[p1][p2];
    int mx = 0, res = 0;
    if(s[p1] == t[p2]) {
        res = 1 + solve(p1+1, p2+1);
        if(res > mx){
            mx = res;
            ans[p1][p2] = 0;
        }
    }
    else 
    {
        res = solve(p1+1, p2);
        if(res > mx){
            mx = res;
            ans[p1][p2] = 1;
        }
        res = solve(p1, p2+1);
        if(res > mx){
            mx = res;
            ans[p1][p2] = 2;
        }
    } 
    return dp[p1][p2] = mx;
}

void print_ans(int p1, int p2){
    if(p1 >= ls || p2 >= lt) return;

    if(s[p1]==t[p2]) res += s[p1];
    if(ans[p1][p2]==0) print_ans(p1+1, p2+1);
    else if(ans[p1][p2]==1) print_ans(p1+1, p2);
    else print_ans(p1, p2+1);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>s>>t;
    ls = s.size();
    lt = t.size();
    solve(0, 0);
    print_ans(0, 0);
    cout << res << "\n";

}