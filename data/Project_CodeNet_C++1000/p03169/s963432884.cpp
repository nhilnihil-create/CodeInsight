#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define test(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define loop(i,start,end) for(ll i=start; i<end; i++)
#define rloop(j,start,end) for(ll j=start-1; j>=end; j--)

ll n;
double dp[305][305][305];

void init(){
	
	loop(i,0,301)
		loop(j,0,301)
			loop(k,0,301)
				dp[i][j][k]=-1;
}

double expDP(ll x,ll y,ll z)
{
	if(x==0 && y==0 && z==0)
		return 0.0;
		
	if(x<0 || y<0 || z<0)
		return 0.0;
		
	if(dp[x][y][z]!=-1)
		return dp[x][y][z];
	
	double ans;
	ans = (n + expDP(x-1,y,z)*x + expDP(x+1,y-1,z)*y + expDP(x,y+1,z-1)*z)/(x+y+z);
	
	dp[x][y][z]=ans;
	
	return ans;
}

int main()
{   
    IOS;
	
	init();
    cin>>n;

    ll p[n],one=0,two=0,three=0;
    loop(i,0,n)
    {
        cin>>p[i];

        if(p[i]==1)
            one++;
        else if(p[i]==2)
            two++;
        else
            three++;
    }

    cout<<fixed<<setprecision(12)<<expDP(one,two,three)<<endl;

}