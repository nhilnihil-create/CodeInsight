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
    vector<vector<int>> c(3,vector<int>(3));
    rep(i,3)rep(k,3)cin >> c[i][k];
    vector<int> a(3),b(3);
    for(int i=0;i<=100;i++)
    {
        a[0]=i;
        b[0]=c[0][0]-i;
        if(b[0]<0)continue;
        for(int k=0;k<=100;k++)
        {
            a[1]=k;
            b[1]=c[1][1]-k;
            if(b[1]<0)continue;
            for(int k=0;k<=100;k++)
            {
                a[2]=k;
                b[2]=c[2][2]-k;
                if(b[2]<0)continue;
                bool ok=true;
                for(int t=0;t<=2;t++)for(int p=0;p<=2;p++)
                {
                    if(c[t][p]==a[t]+b[p])continue;
                    ok = false;
                    break;
                }
                if(ok)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}