#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false)
#define ll  long long
ll a[300300], b[302000], vs[3000000];
vector<ll>v;

int main()
{
    IO;
    ll i, j=1, k = 0, mod = 1e9+7, m, mx, n, l = 1, p, t, h, kk=0, cnt=0;

    cin>>n>>m;
    for(i=1; i<=n; i++) j*=2;
    if(m==1&&n==1) return cout<<-1<<endl, 0;
    while(m){
        if(m%2&&l<1e6) vs[l]=1;
        m/=2; l*=2;
    }
    if(l/2>=j)cout<<-1<<endl;
    else {
        for(i=0; i<j; i++)
            if(!vs[i]) cout<<i<<' ';
        for(i=0; i<j; i++)
            if(vs[i]) cout<<i<<' ';
        for(i=j-1; i>=0; i--)
            if(!vs[i]) cout<<i<<' ';
        for(i=j; i>=0; i--)
            if(vs[i]) cout<<i<<' ';
    }
    return 0;
}
