#include<bits/stdc++.h>
#define ll long long
#define dl double
#define mp make_pair
#define pb push_back
using namespace std;

//***********************************************************************

// hash struct for unordered_map
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

int MAXNUM = 5e3+5;
vector <int>vis(MAXNUM);
vector<int> pr;
void sieve() {
	pr.push_back(2);
	for(ll i=3;i<MAXNUM;i+=2) if(!vis[i]) {
		pr.push_back(i);
		for(ll j=i*i;j<MAXNUM;j+=2*i) vis[j]=true;
	}
}
//************************************************************************

struct box{
    ll w,s,v;
};

bool cmp(box &A,box &B)
{
    return (A.w+A.s)<(B.w+B.s);
}
ll dp[1000][20001];
void solve()
{
    ll n;
    cin >> n;
    vector<box> boxs(n);
    for(int i=0;i<n;i++)
    {
        cin >> boxs[i].w >> boxs[i].s >> boxs[i].v;
    }
    sort(boxs.begin(),boxs.end(),cmp);
    memset(dp,0,sizeof dp);
     //cout << "c0 " << endl;
    //base case
    for(int i=0;i<20001;i++)
    {
        if(boxs[0].w<=i)
        dp[0][i]=boxs[0].v;
    }
    //cout << "c1 " << endl;
    // fill the dp
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<20001;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(boxs[i].w<=j)
            {
                dp[i][j]=max(dp[i][j],boxs[i].v+dp[i-1][min(boxs[i].s,j-boxs[i].w)]);
            }
        }
    }
     //cout << "c2 " << endl;
    ll ans=0;
    for(int i=0;i<20001;i++)
    ans=max(ans,dp[n-1][i]);
     //cout << "c3 " << endl;
    cout << ans << endl;

}


int main()
{ 
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	ll t;
	//cin >> t;
	t=1;
	while(t--)
	{
		solve();
	}

	return 0;
}