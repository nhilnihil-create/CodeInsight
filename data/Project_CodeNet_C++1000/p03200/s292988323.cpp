#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    string s;
    cin >>s;
    bool ok=true;
    ll cnt=0,sum=0;
    rep(i,s.length())
    {
        if(s[i]=='B')cnt++;
        else sum+=cnt;
    }
    cout<<sum<<endl;
    return 0;
}