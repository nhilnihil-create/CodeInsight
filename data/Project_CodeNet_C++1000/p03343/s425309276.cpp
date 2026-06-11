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
int a[2005];
int32_t main()
{
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> v;
    ii cin>>a[i],v.push_back(a[i]);
    sort(all(v));
    int ans = 2e9;
    for(int i=0;i<v.size();++i) {
        for(int j=1;j<=n;++j) if(a[j] < v[i]) a[j] = 0;
        vector<int> tmp, tot;
        for(int j=1;j<=n;++j) {
            if(!a[j])
            {
                sort(all(tmp));
                for(int i=0;i<(int)tmp.size()-k+1;++i) tot.push_back(tmp[i]);
                tmp.clear();
            }
            else tmp.push_back(a[j]);
        }
        if(tmp.size())
        {
            sort(all(tmp));
            for(int i=0;i<(int)tmp.size()-k+1;++i) tot.push_back(tmp[i]);
        }
        if(tot.size() < q) break;
        else
        {
            sort(all(tot));
            ans = min(ans, tot[q-1] - tot[0]);
        }
    }
    cout << ans << endl;
}
