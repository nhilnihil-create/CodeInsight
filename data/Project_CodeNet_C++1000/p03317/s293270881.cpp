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
    int n,k;
    cin >> n >> k;
    int MIN = 1e6;
    int cnt=1;
    rep(i,n)
    {
        int a;
        cin >> a;
        if(MIN>a){
            MIN=a;
            cnt=1;
        }
        else if(MIN==a)cnt++;
        
    }
    int ans;
    if((n-cnt)%(k-1)==0)ans = (n-cnt)/(k-1);
    else ans = (n-cnt)/(k-1)+1;
    cout <<ans<<endl;
    return 0;
}