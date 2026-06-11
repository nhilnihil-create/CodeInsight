#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define inf LLONG_MAX>>2
#define MAX 1000000
#define mod 1000000007
#define pb push_back
#define f(i,a,n,x) for ((i)=(a);(i)<(n);(i)+=(x))
#define fd(i,a,n,x) for ((i)=(a);(i)>=(n);(i)-=(x))
#define fi first
#define se second
#define mk make_pair
#define pi pair
#define vt vector
using namespace std;
void read(vt<ll> &a,ll n){ll i,temp;f(i,0,n,1){cin>>temp;a.pb(temp);}}
void solve(){
    ll n,i=0,j,k,temp,ans=0;
    cin>>n;
    vt<ll> a,b,c,medium(n+3),largest(n+3);
    read(a,n);
    read(b,n);
    read(c,n);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    f(j,0,n,1){
        temp=0;
        while(b[j]>a[i] && i<n){
            temp++;
            i++;
        }
        if (i>=n)
            i=n;
        medium[j]=((j-1)>=0?medium[j-1]:0)+temp;
    }
    j=0;
    f(k,0,n,1){
        temp=0;
        while(c[k]>b[j] && j<n){
            temp+=medium[j];
            j++;
        }
        if (j>=n)
            j=n;
        largest[k]=((k-1)>=0?largest[k-1]:0)+temp;
    }
    f(i,0,n,1)
        ans+=largest[i];
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}