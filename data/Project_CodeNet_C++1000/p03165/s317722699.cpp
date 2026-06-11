#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define deb(x) cout << #x << "=" << x << endl

int main() {
	// your code goes here
	ll t;
	t=1;
	while(t--)
	{
	    string a,b;
	    cin>>a;
	    cin>>b;
	    ll n=a.length();
	    ll m=b.length();
	    ll t[n+1][m+1];
	    for(ll i=0;i<n+1;i++)
	    {
	        t[i][0]=0;
	    }
	    for(ll j=0;j<m+1;j++)
	    {
	        t[0][j]=0;
	    }
	    for(ll i=1;i<n+1;i++)
	    {
	        for(ll j=1;j<m+1;j++)
	        {
	            if(a[i-1]==b[j-1])
	            t[i][j]=1+t[i-1][j-1];
	            else
	            t[i][j]=max(t[i-1][j],t[i][j-1]);
	        }
	    }
	   /*for(ll i=0;i<n+1;i++)
	   {
	       for(ll j=0;j<m+1;j++)
	       {
	           cout<<t[i][j]<<" ";
	       }
	       cout<<"\n";
	   }*/
	   string ans="";
	   ll i=n;
	   ll j=m;
	   if(t[n][m]==0)
	   ans.pb(' ');
	   while(i>0 && j>0)
	   {
	       if(a[i-1]==b[j-1])
	       {
	           ans.pb(a[i-1]);
	           i--;
	           j--;
	       }
	       else
	       {
	           if(t[i][j-1]>=t[i][j])
	           j--;
	           else
	           i--;
	       }
	   }
	   reverse(ans.begin(),ans.end());
	   cout<<ans;
	}
	return 0;
}