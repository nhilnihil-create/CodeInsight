#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool check(ll n,ll pos)
{
    return n & (1ll<<pos);
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,k;
    ll bits[50];
    ll one[50]= {0};
    ll zero[50]= {0};
    bits[0]=1;
    ll sum=0;
    for(int i=1; i<=42; i++)
    {
        bits[i]=bits[i-1]*2ll;
    }
    cin>>n>>k;
    vector<ll>v;
    int lim=0;
    for(int i=0; i<n; i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
        sum+=a;
        for(int i=0; i<=40; i++)
        {
            if(check(a,i))
            {
                one[i]++;
                lim=max(lim,i);
            }
        }
    }
    for(int i=0; i<=40; i++)
    {
        zero[i]=n-one[i];
    }
    ll mx=sum,cur_k=k;
    for(int i=40; i>=0; i--)
    {
        if(zero[i] && cur_k>=bits[i])
        {
            ll x=sum-(one[i]*bits[i]);
            x+=(zero[i]*bits[i]);
            if(x>mx)
            {
                mx=x;
                sum=x;
                cur_k-=bits[i];
            }
        }
    }
    cout<<sum<<endl;


    return 0;
}
