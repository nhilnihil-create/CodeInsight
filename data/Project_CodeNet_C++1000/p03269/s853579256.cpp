#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[22];
int main()
{
    int l;
    cin >> l;
    if(l&(1<<19))
    {
        int m = 0;
        vector<pair<int,int>> ans;
        int cur = 0;
        for(int i=19;i>=0;--i)
        {
            if(l&(1<<i))
            {
                if(i != 19) ans.push_back({i+1, cur});
                cur = cur + (1<<i);
            }
        }
        cout << 20 << " " << ans.size() + 38 << endl;
        for(int i=1;i<=19;++i)
        {
            cout << i << " " << i+1 << " " << 0 << endl;
            cout << i << " " << i+1 << " " << (1<<(i-1)) << endl;
        }
        for(auto p : ans) cout << p.first << " " << 20 << " " << p.second << endl;
    }
    else
    {
        int m = 0;
        vector<pair<int,int>> ans;
        int cur = 0;
        for(int i=0;i<=19;++i)
        {
            if(l&(1<<i))
            {
                ++m;
                ans.push_back({i+1, cur});
                cur = cur + (1<<i);
            }
        }
        cout << 20 << " " << m + 36 << endl;
        for(int i=1;i<=18;++i)
        {
            cout << i << " " << i+1 << " " << 0 << endl;
            cout << i << " " << i+1 << " " << (1<<(i-1)) << endl;
        }
        for(auto p : ans) cout << p.first << " " << 20 << " " << p.second << endl;
    }
}
