/*Rabbi Zidni Ilma*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define mod 1000000007
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)

ll L[3005][3005];

int main()
{
	ll l1,l2,i,j;
    string s,t;
    cin >> s >> t;
    l1=s.size();
    l2=t.size();
    for(i=0;i<=l1;i++)
    {
    	for(j=0;j<=l2;j++)
    	{
    		if(i==0||j==0)
    		L[i][j]=0;
    		else if(s[i-1]==t[j-1])
    		L[i][j]=1+L[i-1][j-1];
    		else
    		L[i][j]=max(L[i-1][j],L[i][j-1]);
		}
	}
	
	string ans;
	i=l1,j=l2;
	while(i>0&&j>0)
	{
		if(s[i-1]==t[j-1])
		{
			ans.pb(s[i-1]);
			i--;
			j--;
		}
		else if(L[i-1][j]>L[i][j-1])
		i--;
		else 
		j--;
	}
	reverse(ans.begin(),ans.end());
	cout << ans <<"\n";
}



