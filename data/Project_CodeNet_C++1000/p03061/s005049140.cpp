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


int tc,n,a[100005],l[100005],r[100005];


void sol()
{

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    l[0]=a[1];
    r[n+1]=a[n];
    for(int i=1,j=n; i<=n; i++,j--){
        l[i]=__gcd(a[i],l[i-1]);
        r[j]=__gcd(a[j],r[j+1]);
    }
    int mx=0;
    for(int i=1; i<=n; i++){
        int le=l[i-1];
        int ri=r[i+1];
        int po=__gcd(le,ri);
        if(i==1)po=ri;
        if(i==n)po=le;
        mx=max(mx,po);
    }
    cout<<mx<<endl;
}

int main()
{

    _fastIO;

    //cin>>tc;while(tc--)
    sol();

    return 0;
}
