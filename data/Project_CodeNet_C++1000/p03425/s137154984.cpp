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
    cin >> n;
    vector<int>s(5);
    rep(i,5)s[i]=0;
    rep(i,n)
    {
        string ss;
        cin >> ss;
        switch (ss[0])
        {
        case 'M':
            s[0]++;
            break;
        case 'A':
            s[1]++;
            break;
        case 'R':
            s[2]++;
            break;
        case 'C':
            s[3]++;
            break;
        case 'H':
            s[4]++;
            break;
        }
    }
   
    ll ans=0;
    for(int i=0;i< (1<<5);i++)
    {
        if(__builtin_popcount(i)!=3)continue;
        ll sum=1;
        for(int k=0;k<5;k++)
        {
            if(i&(1<<k))
            {          
                    sum *=s[k]; 
            }
        }
        ans+=sum;
       
    }
     cout<<ans<<endl;
    return 0;
}