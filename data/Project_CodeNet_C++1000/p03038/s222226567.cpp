#include<bits/stdc++.h>

#define forOneToN(i, n)         for(int i = 1; i <= n; i++)
#define forZeroToNminus(i, n)   for(int i = 0; i < n; i++)
#define forNToOne(i, n)         for(int i = n; i >= 1; i--)
#define forNminusToZero(i, n)   for(int i = n-1; i >= 0; i--)


#define makepair                make_pair
#define pushback                push_back

//Test Code
#define test                    cout <<"I am here" << endl;
#define YES                     cout <<"YES" << endl;
#define NO                      cout <<"NO" << endl;
#define yes                     cout <<"Yes" << endl;
#define no                      cout <<"No" << endl;
using namespace std;
void fastInputOutput(){ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long ll;
typedef double db;


typedef vector<int>                                                             vii;
typedef vector<long long>                                                       vll;
typedef vector< pair<int, int> >                                                vpii;
typedef vector< pair<long long, long long> >                                    vpll;
typedef vector< pair<long long, int> >                                          vpli;
typedef vector< pair<int, long long> >                                          vpil;
typedef pair<int, int>                                                          pii;
typedef pair<long long, long long>                                              pll;
typedef pair<long long, int>                                                    pli;
typedef pair<int, long long>                                                    pil;
typedef map<int, int>                                                           mii;
typedef map<long long, long long>                                               mll;
typedef map<long long, int>                                                     mli;
typedef map<int, long long>                                                     mil;
typedef multimap<int, int>                                                      mmii;
typedef multimap<long long, int>                                                mmli;
typedef multimap<int, long long>                                                mmil;
typedef multimap<long long, long long>                                          mmll;
typedef set<int>                                                                si;
typedef set<long long>                                                          sll;
typedef multiset<int>                                                           msi;
typedef multiset<long long>                                                     msll;
typedef set<long long, greater<long long> >                                     slld;
typedef set<int, greater<int> >                                                 sid;
typedef multiset<int, greater<int> >                                            msid;
typedef multiset<long long, greater<long long> >                                mslld;
typedef stack<long long>                                                        stll;
typedef stack<int>                                                              sti;
typedef queue<long long>                                                        qll;
typedef queue<int>                                                              qi;
typedef priority_queue<long long>                                               maxpqll;
typedef priority_queue<int>                                                     maxpqi;
typedef priority_queue<long long, vector<long long>, greater<long long> >       minpqll;
typedef priority_queue<int, vector<int>, greater<int> >                         minmpqi;



ll GCD(ll a, ll b){ll gcd, g;g = __gcd(a, b);return g;}
ll gcd(ll a, ll b){if(b == 0){return a;}else{return gcd(b, a%b);}}
ll extended_gcd(ll a, ll b, ll *x, ll *y){if(a == 0){*x = 0;*y = 1;return b;}ll x1, y1;ll d = extended_gcd(b%a, a, &x1, &y1);*x = y1-(b/a)*x1;*y = x1;return d;}
ll LCM(ll a, ll b){ll gcd, g;g = __gcd(a, b);return (a/g)*b;}
ll PowFun(ll base, ll power){ll ans = 1;for(int i = 1; i <= power; i++){ans *= base;}return ans;}
/*This is better power function here used binary exponentiation*/
ll MadeFun(ll b, ll p){if(p == 0){return 1;}else if(p%2 == 0){return MadeFun(b*b, p/2);}else{return b*MadeFun(b*b, (p-1)/2);}}


const ll INF_LONG = 1LL<<61;
const unsigned int inf_int = 1<<31;
const ll mod = 1e9+7;
double phi = acos(-1);


//own compare function structure for vector pair
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first != b.first)
    {
        return a.first > b.first;
    }
    return a.second > b.second;
}

void solve()
{
    int n, m; cin >> n >> m;
    int a[n+5] = {};
    for(int i  = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int pos = 1;
    vector< pair<int, int> >vp;
    for(int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        vp.push_back(make_pair(v, u));
    }
    sort(vp.begin(), vp.end(), greater< pair<int, int> >());
    for(int i = 0; i < vp.size(); i++)
    {
        int u = vp[i].first;
        int v = vp[i].second;
        int tem = pos;
        for(int j = pos; j <= min(pos+v-1, n); j++)
        {
            if(a[j] < u)
            {
                a[j] = u;
                tem = j+1;
            }
            else
            {
                break;
            }
        }
        pos = tem;
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
    }
    cout << sum << endl;
}
int main()
{
    solve();
    return 0;
}
