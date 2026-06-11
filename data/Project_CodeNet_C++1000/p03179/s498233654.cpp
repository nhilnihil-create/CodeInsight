#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
typedef long long ll;
const int mod = 1e9+7;
int dp[3005][3005];
void self_add(int &a, int b)
{
    a+=b;
    if(a >= mod) a-=mod;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    dp[1][1] = 1;
    fo(j,2,n+1)
    {
        vector <int>pre(n+1);
        fo(k,1,j) pre[k] = (pre[k-1] + dp[j-1][k])%mod;
        fo(i,1,j+1)
        {
            int l, r;
            if(s[j-2] == '>') l = i, r = j-1;
            else l = 1, r = i-1;
            dp[j][i] += ((pre[r] - pre[l-1] + mod) % mod);
            dp[j][i] %= mod;
            /*fo(k,1,j)
            {
                //int a = k;
                //if(k >= i) a++;
                //assert(a != i);
                //if((a < i) != (s[j-2] == '<')) continue;
                if(s[j-2] == '>' && i <= k) continue;
                if(s[j-2] == '<' && i > k) continue;
                self_add(dp[j][i], dp[j-1][k]);
            }*/
        }
    }
    int res = 0;
    fo(i,1, n+1) self_add(res, dp[n][i]);
    cout << res << endl;


}
