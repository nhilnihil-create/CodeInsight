#include<bits/stdc++.h>
#include<ctype.h>
# define pb push_back
#define fst first
#define sec second
#define For(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
#define fo(i,n) for(ll i=0;i<n;i++)
#define endl "\n"
#define rev(i,n) for(ll i=n-1;i>=0;i--)
#define fo1(i,n) for(ll i=1;i<=n;i++)
#define boolsize 1000001
#define pi pair<ll,ll>
#define vi vector<ll>
#define vii vector<pi>
using namespace std;
template<typename T>
void showvector(vector <T> v)
{
    for(T x:v)
        cout<<x<<" ";
    cout<<endl;

}
template<typename T>
void showvector1(vector <T> v)
{
    ll n=v.size();
    fo1(i,n-1)
        cout<<v[i]<<endl;

}
template<typename T>
void showset(set <T> s)
{
    for(T x: s)
        cout<<x<<" ";
    cout<<endl;
}
template<class T>
void showvectorpair(vector<T> v)
{
    for(auto it=v.begin();it!=v.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    cout<<endl;
}
template<typename T,typename P>
void showmap(map <T,P> m)
{
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    cout<<endl;
}
template<typename T>
bool comp(T a,T b)
{
    return (a>b);
}
template<class T>
bool comppair(T a,T b)
{
    if(a.first==b.first)
        return(a.second>b.second);
    return (a.first>b.first);
}
bool sameparity(ll a,ll b)
{
    return (a%2==b%2);
}
bool difparity(ll a,ll b)
{
    return !(a%2==b%2);
}
bool isprime(ll x)
{   if(x<=1)
     return false;
    for(ll i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
bool iseven(ll x)
{
    return !(x%2);
}
bool isodd(ll x)
{
    return (x%2);
}
/// check for test case before submitting
void vfun()
{
    ll n,k;
    cin>>n;
    vector <ll> v(n);
    fo(i,n)
    cin>>v[i];

}
const int siz=100001;
ll t[101][siz],pre[101][siz];
vector <ll> v(101);
ll sol(ll n,ll k)
{
    if(k==0)
        return 1;
    if(n==0)
        return 0;
    if(t[n][k]!=-1)
        return t[n][k];
    ll ans=0;
    //ll mn=min(v[n-1],k);
    for(ll i=0;i<=v[n-1];i++)
    {
        if(k-i>=0)
            {ans+=sol(n-1,k-i);
            ans%=mod;
            }
    }

    return t[n][k]= ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputh.txt", "r", stdin);
    freopen("outputh.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); ///cant use scanf, printf
    cin.tie(0);cout.tie(0); /// no longer auto flush cout before each cin, remove for interactive
    //cout << fixed << setprecision(11); /// no scientific output
    ll test=1;
    //cin>>test;
   // exit(0);
    //memset(t,-1,sizeof(t));
    while(test--)
    {

            ll n,k;
            cin>>n>>k;
            fo(i,n)
                cin>>v[i];
           //cout<<sol(n,k);
        for(int i=0;i<=k;i++)
            t[0][i]=0,pre[0][i]=1;
        for(int i=0;i<=n;i++)
            t[i][0]=1,pre[i][0]=1;
        fo1(i,n)
        {
            fo1(j,k)
            {
                if(j-v[i-1]-1>=0)
                    t[i][j]=((pre[i-1][j]-pre[i-1][j-v[i-1]-1])%mod+mod)%mod;
                else
                    t[i][j]=(pre[i-1][j])%mod;
                pre[i][j]=(pre[i][j-1]+t[i][j])%mod;
            }
        }
//        fo(i,n){
//        fo(j,k){
//        cout<<pre[i][j]<<" ";}
//        cout<<endl;}
        cout<<t[n][k]<<endl;
//         if(vfun())
//            cout<<"YES\n";
//         else
//            cout<<"NO\n";
    }
}
///before sub
/// check for value of zero and single input in array
///loop vars,1LL in mult, equal, one, bounds, int v ll, endl, finish taking inputs
/// check whether test cases are given or not




