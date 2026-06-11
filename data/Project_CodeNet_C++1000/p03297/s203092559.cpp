#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a<b) {cout<<"No"<<endl;continue;}
        if(d<b) {cout<<"No"<<endl;continue;}
        if(c>=b) {cout<<"Yes"<<endl;continue;}
        ll tmp = gcd(b,d%b);
        ll k = (b-a%b-1)/tmp*tmp+a%b;
        if(c+1 <= k && k <= b-1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
