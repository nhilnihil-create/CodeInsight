#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define leading zero str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
string text="abcdefghijklmnopqrstuvwxyz";
const int maxn=1e6+7;
//        .--------------.
//        | Try First One|
//        '--------------'
//                |     .--------------.
//                |     |              |
//                V     V              |
//              .--------------.       |
//              |      AC.     |<---.  |
//              '--------------'    |  |
//              (True)|  |(False)   |  |
//           .--------'  |          |  |
//           |           V          |  |
//           |  .--------------.    |  |
//           |  |   Try Again  |----'  |
//           |  '--------------'       |
//           |                         |
//           |  .--------------.       |
//           '->| Try Next One |-------'
//              '--------------'
ll bin_pow(ll a,ll b,ll m)
{
    ll res=1;
    a%=m;
    while(b>0)
    {
        if(b&1)
            res=res*a%m;
        b>>=1;
        a=a*a%m;
    }
    return res;
}
bool miller_rabin(ll d,ll n)
{
    ll a=2+rand()%(n-4);
    ll x=bin_pow(a,d,n);
    if(x==1 || x==n-1)
        return true;
    while(d!=n-1)
    {
        x=(x*x)%n;
        d*=2;
        if(x==1)
            return false;
        if(x==n-1)
            return true;
    }
    return false;
}
bool prime(ll n,ll k)
{
    if(n==1 || n==4)
        return false;
    if(n<=3)
        return true;
    ll d=n-1;
    while(d%2==0)
        d/=2;
    for(int i=0; i<k; i++)
    {
        if(!miller_rabin(d,n))
            return false;
    }
    return true;
}
bool p[100005];
void sieve()
{
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for(int i=2;i*i<=100000;i++){
        if(p[i]){
            for(int j=i*i;j<=100000;j+=i){
                p[j]=false;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    vector<int>v;
    for(int i=2;i<=100000;i++)if(p[i]){v.push_back(i);}
    int q;
    cin>>q;
    while(q-->0){
        int l,r,cnt=0;
        cin>>l>>r;
        int id=lower_bound(v.begin(),v.end(),l)-v.begin();
        int ses=lower_bound(v.begin(),v.end(),r)-v.begin();
        if(v[ses]>r)ses--;
        for(int i=id;i<=ses;i++){
            int n=(v[i]+1)/2;
            if(p[n])cnt++;
        }
        cout<<cnt<<endl;
    }
}
