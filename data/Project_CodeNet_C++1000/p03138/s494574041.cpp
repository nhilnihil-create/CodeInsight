//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const ll INF = 1e9;
const ll LINF = ll(1e18) + 1;
const ll MOD = 1000000007;
const ll dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const ll Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll n, k;
vector<ll> a;
ll dight(ll l){
    ll count=0;
    while(l){
        l/=2;
        count++;
    }
    return count;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>k;
    ll keta=dight(k);
    vector<ll> count(60,0);
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
        for(ll j=0;j<59;j++){
            if((1LL<<j)&temp){
                count[j]++;
            }
        }
    }
    /*
    cout<<keta<<"\n";
    debug(count);
    */
    ll ans=0;
    vector<ll> ansd(keta,0);
    for(ll i=59;i>=0;i--){
        if(i>=keta){
            ans+=(1LL<<i)*count[i];
        }
        else{
        if(((1LL<<i)&k)){
            ansd[i]=(1LL<<i)*(count[i])+ans;//あとは自由
            ans+=(1LL<<i)*(n-count[i]);
            
        }
        else{
            ans+=(1LL<<i)*(count[i]);
        }
        for(int j=keta-1;j>i;j--){
            if(ansd[j]!=0)
            ansd[j]+=(1LL<<i)*max((n-count[i]),count[i]);
        }
        }
    }
    /*
    cout<<ans<<"\n";
    debug(ansd);
    */
    rep(i,keta){
        chmax(ans,ansd[i]);
    }
    cout<<ans<<"\n";
}
