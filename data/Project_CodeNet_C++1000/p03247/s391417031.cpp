#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( i = c.begin(); i != c.end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
ll INF=1e18;
const int LIM=1e5+5,MOD=1e9+7;
ll min1(ll a,ll b)
{
    if(a<b)
        return a;
    else return b;
}
int main()
{
    fastio;
    ll N=1010;
    vector<ll> segments;
    vector<string> ans;
    ll in[1010][2];

    ll n;
    cin>>n;
    forn(i,n)
    {
        cin>>in[i][0]>>in[i][1];
    }
     
    ll mod2 = abs((in[0][0] + in[0][1])%2);
    bool possible = true;
     
      // check that they all have same parity
    for(int i=1;i<n;i++)
    {
        if(abs((in[i][0] + in[i][1])%2) != mod2)
        {
            possible = false;
            break;
        }
    }
     
    if(possible)
    {
        if(mod2 == 0)
        {
            segments.pb(1);
        }
        forn(i,31)
        {
          segments.pb(1LL << i);
        }
        forn(i,n)
        {
            ll x = in[i][0], y = in[i][1];
     
            int num_segs = segments.size();
            ll sum = (1LL << 31) - mod2;
            string s("");
            for(int j = num_segs-1; j >= 0; j--)
            {
                sum -= segments[j];
                if(abs(x - segments[j]) + abs(y) <= sum) 
                {
                    s += 'R';
                    x -= segments[j];
                }else if(abs(x + segments[j]) + abs(y) <= sum)
                {
                    s += 'L';
                    x += segments[j];
                } else if(abs(x) + abs(y - segments[j]) <= sum)
                {
                    s += 'U';
                    y -= segments[j];
                } else 
                {
                    s += 'D';
                    y += segments[j];
                }
            }
     
              reverse(s.begin(), s.end());
              ans.pb(s);
        }
     
        cout<<segments.size()<<"\n";
        ll j;
        for(j=0;j<segments.size();j++)
        {
          cout<<segments[j]<<" ";
        }
        cout<<"\n";
        puts("");
        for(j=0;j<ans.size();j++)
        {
          cout<<ans[j]<<endl;
        }
     
        } 
        else
        {
            puts("-1");
        }
        return 0;
}