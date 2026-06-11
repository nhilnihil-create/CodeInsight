/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double lld ;
#define f(i,s,n) for(int i=s;i<(int)n;i++) 
// const int MAXN = 2e5+5 ;
#define pb push_back 
#define X first 
#define Y second 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define pli pair<ll,int> 
#define pil pair<int,ll> 
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<setprecision(10) ;
#define is(x) cout<<#x<<" : "<<x<<endl ;
// #define DEBUG

int main()
{
    fio ;
    /* ======================Start of code ================ */
    string s;cin>>s ;
    int n = s.size() ;
    ll b = 0 ;
    ll total = 0 ;
    f(i,0,n) 
    {
        if(s[i]=='B') b++ ;
        else total+=b ;
    }
    cout<<total<<"\n" ;

    /* ======================End of code ================== */
}