#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second

ll n,k,a[55];

ll solve(ll len)
{
    ll tmp=0 , rem , sum=0 , curSum=0;
    priority_queue<ll , vector<ll> , greater<ll> >q;

    for(int i=0; i<=len; i++)
    {
        while(q.size()) q.pop();
        sum=0;
        for(int j=1; j<=i; j++)
        {
            q.push(a[j]) , sum += a[j];
        }
        rem = len-i;
        for(int j=n; j>n-rem; j--)
        {
            q.push(a[j]) , sum += a[j];
        }
        rem = k-len;
        while(q.size() && q.top() <= 0 && rem)
        {
            rem--;
            sum -= q.top();
            q.pop();
        }
        tmp = max(tmp , sum);
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    ll ans = 0;
    for(int i=1; i<=min(n,k); i++)
    {
        ans = max(ans , solve(i));
    }

    cout << ans << '\n';
	//
  
    return 0;
}