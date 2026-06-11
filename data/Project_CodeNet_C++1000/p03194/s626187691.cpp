#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
//#define mp make_pair
#define ff first
#define ss second
#define debug(x) cout<<"### x is: "<<x<<"###"<<endl
#define all(a) a.begin(),a.end()
#define tc int t;scanf("%d",&t);while (t--0)
#define int long long
const int MOD=1e9+7;
const int N=2e5+5;
int power(int a, int b) {int ret=1;while(b) {if(b&1) ret*=a;a*=a;if(ret>=MOD) ret%=MOD;if(a>=MOD) a%=MOD;b>>=1;}return ret;}
int invmod(int x) {return power(x,MOD-2);}
int pre[N],a[N],b[N];
map<int,int>mp;
int seive(int n)
{
	if(n<=3)
		return 1;
	else if(n%2==0||n%3==0)
		return 0;
	int i=5;
	while(i*i<=n)
	{
		if(n%(i)==0||n%(i+2)==0)
			return 0;
		i+=6;
	}
	return 1;
}
void primeFactors(int n) 
{ 
    
    while (n%2 == 0) 
    { 
        mp[2]++;
        n = n/2; 
    } 
  
     
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        
        while (n%i == 0) 
        { 
            mp[i]++;
            n = n/i; 
        } 
    } 
  
    if (n > 2) 
        mp[n]++;
} 
int32_t main()
{
	int n,m;
	cin>>n>>m;
	primeFactors(m);
	//cout<<mp.size()<<endl;
	map<int,int>:: iterator it;
	int ans=1;
	for(it=mp.begin();it!=mp.end();it++)
	{
		//cout<<it->second<<" "<<it->first<<endl;
		if(((it->second)/n)>0)
			ans*=pow(it->first,it->second/n);
	}
	cout<<ans<<endl;

}