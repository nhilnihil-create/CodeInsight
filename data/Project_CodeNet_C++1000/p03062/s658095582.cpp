#include<bits/stdc++.h>

#define _fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pi acos(-1)
#define MAXS 100000
#define MOD 998244353
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int tc,n,a[100005];


void sol()
{
    int neg=0,pos=0,mn=INT_MAX;
    ll sum=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]<0)neg++;
        sum+=abs(a[i]);
        mn=min(mn,abs(a[i]));
    }
    if(neg&1)sum-=2*mn;
    cout<<sum<<endl;
}

int main()
{

    _fastIO;

    //cin>>tc;while(tc--)
    sol();

    return 0;
}
