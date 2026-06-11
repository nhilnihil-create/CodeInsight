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
    int n;
    cin >> n ;
    int sum=0,pre;
    bool ok=true;
    rep(i,n)
    {
        int a; cin >> a;
        if(ok){
            sum+=a;
            pre=a;
            ok=false;
            continue;
        }
        
        if(a>pre)sum+=a-pre;
        pre=a;
        if(a==0)ok=true;
    }
    cout<<sum<<endl;
    return 0;
}