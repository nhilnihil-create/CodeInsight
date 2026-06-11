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

ll f(ll x)
{
    int ret=0;
    while(x)
    {
        ret+=x%10;
        x/=10;
    }
    return ret;
}
ll nxt(ll x)
{
    string s = to_string(x);
    ll ret = x;
    double mx = 1.0 * x / f(x);
    for(int i=s.size()-1;i>=0;--i) {
        s[i] = '9';
        ll x2 = stoll(s);
        double tmp = 1.0 * x2 / f(x2);
        if(tmp < mx) ret = x2, mx = tmp;
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    ll cur = 1;
    for(int i=1;i<=n;++i)
    {
        cout << cur << endl;
        cur = nxt(cur + 1);
    }
}
