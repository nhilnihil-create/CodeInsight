//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18) + 1;
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
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
vector<ll> t,d;
vector<pair<ll,ll>> v;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>k;
    for (int i = 0; i < n; i++)
    {
        ll temp,temp1;
        cin >> temp>>temp1;
        t.push_back(temp);
        d.push_back(temp1);
        v.push_back(make_pair(temp1,temp));
    }
    sort(ALL(v));
    reverse(ALL(v));
    map<ll,ll> m;
    ll ans=0;
    ll syurui;
    ll count=0;
    priority_queue<ll,vector<ll>,greater<ll>>que;
    rep(i,k){
        m[v[i].second]++;
        if(m[v[i].second]==1)count++;
        if(m[v[i].second]>1)que.push(v[i].first);
        ans+=v[i].first;
    }
    ans+=count*count;
    ll ansa=ans;
    for(int i=k;i<n;i++){
        if(m[v[i].second]||que.empty())continue;
        ll temp=que.top();
        ans-=count*count;
        count++;
        ans+=count*count;
        que.pop();
        ans-=temp;
        ans+=v[i].first;
        m[v[i].second]++;
        chmax(ansa,ans);
    }
    cout << ansa << "\n";
}
