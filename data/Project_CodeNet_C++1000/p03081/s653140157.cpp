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
int n, q;
string t,d,s;
bool checkl(int mid){
    rep(i,q){
        if(mid==-1)return true;
        if(mid==n)return false;
        if(s[mid]==t[i]){
            if(d[i]=='L'){
                mid--;
            }
            else{
                mid++;
            }
        }
    }
    if(mid==-1)return true;
        if(mid==n)return false;
    return false;
}
bool checkr(int mid){
    rep(i,q){
        //cout<<mid<<" ";
        if(mid==-1)return false;
        if(mid==n)return true;
        if(s[mid]==t[i]){
            if(d[i]=='L'){
                mid--;
            }
            else{
                mid++;
            }
        }
    }
    if(mid==-1)return false;
    if(mid==n)return true;
    return false;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>q>>s;
    t="";
    d="";
    for (int i = 0; i < q; i++)
    {
        char temp,temp1;
        cin >> temp>>temp1;
        t+=temp;
        d+=temp1;
    }
    int l=-1;int r=n;
    while(r-l>1){
        int mid=(r+l)/2;
        if(checkl(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    int llimit=l;
    l=-1;
    r=n;
    while(r-l>1){
        int mid=(r+l)/2;
        //cout<<mid<<"\n";
        if(checkr(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
        //cout<<"\n";
    }
    //cout<<llimit<<" "<<r<<"\n";

    cout<<n-(llimit+1)-(n-r)<<"\n";
}
