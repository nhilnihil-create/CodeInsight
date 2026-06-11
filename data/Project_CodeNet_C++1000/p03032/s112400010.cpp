#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int N=2e5+5;
ll mod=1e9+7;

ll mul (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll add (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a+b+mod)%mod;
}
ll fastpow(ll b, ll p)
{
    if(p==0)
        return 1;
    ll ans=fastpow(b,p/2);
    ans=mul(ans,ans);
    if(p%2)ans=mul(ans,b);
    return ans;
}
int n,k;
ll solve(deque<ll>&qq)
{
    ll ans=0;

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {


            deque<ll>q=qq;
            priority_queue<int,vector<int>,greater<int>>pq;
            int co=k;
            for(int x=0; x<i&&q.size(); x++)
            {
                co--;
                pq.push(q.front());
                q.pop_front();
            }
            for(int x=0; x<j&&q.size(); x++)
            {
                co--;
                pq.push(q.back());
                q.pop_back();
            }
            if(co<0)
            {
                continue;
            }
            while(co>0&&pq.size())
            {
                if(pq.top()<0)
                    pq.pop();
                else
                    break;
                co--;

            }
            if(co<0)
                continue;
            ll total=0;
            while(pq.size())
                total+=pq.top(),pq.pop();
          ///  cout<<"i= "<<i<<" j= "<<j<<" total= "<<total<<endl;
            ans=max(ans,total);
        }

    }


    return ans;
}

int main()
{
    FIO
    cin>>n>>k;
    deque<ll>q1,q2;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        q1.push_back(x);
        q2.push_front(x);
    }
    cout<<max(solve(q1),solve(q2));


    return 0;
}

