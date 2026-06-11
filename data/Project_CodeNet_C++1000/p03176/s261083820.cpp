#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define w(x) int x; cin>>x; while(x--)
#define f(i,n) for(ll i=0;i<n;i++)
#define ff first
#define ss second

void ganekasar()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isPrime(ll n)
{
	if(n<=2)
		return false;
		
	for(ll i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	
	return true;
}

int main() 
{
    ganekasar();
    
    int n;
    cin>>n;

    int base = 1;

    while(base <= n)
        base = base*2;

    vector<ll> tree(2*base);

    vector<int> h(n), a(n);

    f(i,n) cin>>h[i];

    f(i,n) cin>>a[i];

    vector<ll> dp(n+1);

    for(int flower=0; flower<n; flower++)
    {
        int x = h[flower] + base;
        ll best = 0;

        while(x>1)
        {
            if(x%2 == 1)
                best = max(best, tree[x-1]);
            x = x/2;
        }

        dp[h[flower]] = best + a[flower];

        for(int i=base+h[flower]; i>=1; i=i/2)
            tree[i] = max(tree[i], dp[h[flower]]);
    }

    ll answer = *max_element(dp.begin(), dp.end());

    cout<<answer<<endl;

    return 0; 
} 