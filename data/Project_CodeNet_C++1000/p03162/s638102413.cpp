/* ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ */
/* ☻ Name : Souvik Mahato  ☻ */
/* ☻ Nick : WIZARDO        ☻ */
/* ☻ Institution : IIEST   ☻ */
/* ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ ☻ */

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define in(v) (v).begin(),(v).end()
#define rin(v) (v).rbegin(),(v).rend()
#define inf 1e9+7



int solvius()
{
    int n;
    cin>>n;
    vector<int> dp(3);
    for(int i=0;i<n;i++)
    {
        vector<int> a(3),new_dp(3,0);
        cin>>a[0]>>a[1]>>a[2];
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
                if(j!=k)
                    new_dp[k] = max(new_dp[k],dp[j]+a[k]) ;
        }
        dp = new_dp;
    }
    cout<<*max_element(in(dp));
    return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    
	ll t=1;
   // cin>>t;
	while(t--)
		solvius();
    return 0;
}