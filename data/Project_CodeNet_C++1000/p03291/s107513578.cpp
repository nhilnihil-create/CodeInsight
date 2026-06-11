#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979
#define EPS 1e-8
#define mod 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl "\n"
	 
const ll INF=(ll)2e18;
		
		
const int N=2e5+5;
	
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}	
		
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
				
	string s;
	cin>>s;
	ll cnt1=0,cnt2=0,ans=0;
	ll cnt=0;
	for(ll i=0;i<s.length();i++)
	{
		if(s[i]=='A')
			cnt1+=binpow(3LL,cnt,mod);
		else if(s[i]=='B')
			cnt2+=cnt1;
		else if(s[i]=='C')
			ans+=cnt2;
		else
		{
			cnt++;
			ans=(ans*3)+cnt2;	
			cnt2=(((cnt2*3))+cnt1);
			cnt1=cnt1*3;
			cnt1+=binpow(3LL,cnt-1,mod);
		}	
		cnt1%=mod;
		ans%=mod;
		cnt2%=mod;
		cnt%=mod;
		
		
			
	}
	ans%=mod;
	cout<<ans;
				
}
