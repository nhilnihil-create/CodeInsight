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
bool prime[MAX];
int prime_numbers[9999999],pos;
void sieve()
{
    prime[0]=1;
    prime[1]=1;
    for(int i=4; i<=MAX; i+=2)
        prime[i]=1;
    int root = sqrt(MAX);
    for(int i=3; i<=root; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=MAX; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    prime_numbers[pos++]=2;
    for(int i=3; i<MAX; i+=2)
        if(prime[i]==0)
            prime_numbers[pos++]=i;
}
ll sum(ll n)
{
    return (n*(n-1))/2;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    sieve();
    ll n;
    cin>>n;
    map<int,int>mp;
    vector<ll>v;
    for(int i=0; i<pos; i++)
    {
        int cnt=0;
        int temp=prime_numbers[i];
        if(temp>n)
            break;
        while(temp<=n)
        {
            int cur=n/temp;
            cnt+=cur;
            temp*=prime_numbers[i];
        }
        if(cnt>1)
        {
            v.push_back(cnt+1);
        }
    }
    ll ans=0;
    sort(all(v));
    int sz=v.size();
    for(int i=0; i<sz; i++)
    {
        ll cnt=0;
        if(v[i]>=3)
            for(int j=0; j<sz; j++)
            {
                if(v[j]>=5 && j!=i)
                    cnt++;
            }
        ans+=sum(cnt);
    }
    for(int i=0; i<sz; i++)
    {
        ll cnt=0;
        if(v[i]>=5)
            for(int j=0; j<sz; j++)
            {
                if(v[j]>=15 && j!=i)
                    cnt++;
            }
        ans+=cnt;
    }
    for(int i=0; i<sz; i++)
    {
        int cnt=0;
        if(v[i]>=3)
            for(int j=0; j<sz; j++)
            {
                if(v[j]>=25 && j!=i)
                    cnt++;
            }
        ans+=cnt;
    }
    for(int i=0; i<sz; i++)
    {
        int cnt=0;
        if(v[i]>=75)
            ans++;
    }
    cout<<ans<<endl;




    return 0;
}
