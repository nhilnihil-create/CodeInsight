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
    int r,d,x;
    cin>>r>>d>>x;
    for(int i=2000;i<2010;i++)
    {
        x=r*x-d;
        cout<<x<<endl;
        
    }
    
    return 0;

}
