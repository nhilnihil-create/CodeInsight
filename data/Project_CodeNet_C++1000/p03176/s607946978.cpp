#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
using namespace std;
ll binpow(ll x,ll y)/* (x^y)%p in O(log y) */{ll res=1;while (y > 0){if(y&1)res=(res*x);y = y>>1;x=(x*x);}return res;}
ll binpowmod(ll x,ll y,ll p)/* (x^y)%p in O(log y) */{ll res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
ll mod_inverse(ll n,ll p)/* Returns n^(-1) mod p */{return binpowmod(n,p-2,p);}
ull gcd(ull x,ull y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
bool comp(pair<int,int> x,pair<int,int> y)
{
    if(x.first<y.first)
        return true;
    else if(x.first==y.first)
        return x.second>y.second;
    else
        return false;
}
bool comp_pairs_by_s(pair<ll,ll> &x ,pair<ll,ll> &y)
{
    return x.second<y.second;
}
bool isPowerOfTwo (ll x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
}

class cmp      //comparator for priority_queue 
{               //declaration: priority_queue<int,vector<int>,cmp>
public:         
    bool operator()(pair<int,int> A,pair<int,int> B)
    {
        if(abs(A.first-A.second)==abs(B.first-B.second))
            return A.first>B.first;
        return abs(A.first-A.second)<abs(B.first-B.second);
    }
};
// int prime[100005]={0};
// void sieve(void)
// {
//  int i,j;
//  for(i=0;i<100005;i++)
//         prime[i]=1;
//  prime[0]=0,prime[1]=0;
//  for(i=2;i<=sqrt(100005);i++){
//      if(prime[i]){
//          for(j=i*i;j<100005;j+=i){
//              prime[j]=0;
//          }
//      }
//  }
    
// }
void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
vector<ll> stree;
ll dp[2000001];
void solve()
{   
    int n;
    cin>>n;
    vector<int> h(n);
    vector<ll> a(n);
    for(auto &it : h)
        cin>>it;
    for(auto &it : a)
        cin>>it;
    int base=1;
    while(base<=n)
        base*=2;
    stree.resize(2*base,0);
    //cout<<base;
    for(int i=0;i<n;i++){
        //find the max height in [0,h[i])
        int r=h[i]+base;
        ll best=0;
        while(r>0){
            if(r%2)
                best=max(best,(ll)stree[--r]);
            r/=2;
        }
        dp[h[i]]=best+a[i];
        //update segment tree with dp[h[i]];
        r=h[i]+base;
        stree[r]=dp[h[i]];
        r/=2;
        while(r>0){
            stree[r]=max(stree[2*r],stree[2*r+1]);
            r/=2;
        }
    }
    ll ans=0;
    for(int i=0;i<2000001;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
