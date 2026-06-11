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
int n;

dl dp[301][301][301];
dl finddpvalue(int x,int y, int z)
{
    //cout << "x : " <<x  << " y : " << y << " z : " << z << endl;
    if(x==0 && y==0 && z==0)
    {
        return 0.0;
    }
    if(dp[x][y][z]!=-1.0)
    return dp[x][y][z];

    dl ans=1.0;
    if(x>0)
    ans+=x*finddpvalue(x-1,y,z)/n;
    if(y>0)
    ans+=y*finddpvalue(x+1,y-1,z)/n;
    if(z>0)
    ans+=z*finddpvalue(x,y+1,z-1)/n;
    ans=n*ans/(x+y+z);
    return dp[x][y][z]=ans;
}


void solve()
{
    cin >> n;
    int n1=0,n2=0,n3=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x==1)
        n1++;
        if(x==2)
        n2++;
        if(x==3)
        n3++;
    } 
    for(int i=0;i<301;i++)
    {
        for(int j=0;j<301;j++)
        {
            for(int k=0;k<301;k++)
            dp[i][j][k]=-1.0;
        }
    }
    //cout << "c0" << endl;
    dl ans=finddpvalue(n1,n2,n3);
    //cout << "c1" << endl;
    cout << setprecision(12) << fixed << ans << endl;
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