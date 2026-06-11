#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15);
    cout<<fixed;
    lli d=0ll,n=0ll,m=0ll;
    cin>>n>>m>>d;
    --m;
    if(d==0ll)
    	cout<<(long double)(m)/n;
    else
    	cout<<(long double)(2ll*m*(n-d))/(1ll*n*n);
    cout<<endl;
}