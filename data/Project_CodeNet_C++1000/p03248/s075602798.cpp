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

int a[100005];
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    ii a[i]=(s[i-1]=='1');
    if(a[n]) return cout<<-1<<endl,0;
    if(!a[1] || !a[n-1]) return cout<<-1<<endl,0;
    for(int i=2;i<=n-2;++i) if(a[i] && !a[n-i]) return cout<<-1<<endl,0;
    int tp = 0, rt = 0, sz = 0;
    vector<pair<int,int>> ans;
    for(int i=2;i<=n/2;++i)
    {
        if(a[i])
        {
            ++tp;
            int nxt = tp;
            if(sz) ans.push_back({nxt, rt});
            for(int j=1;j<=i-sz-1;++j) ans.push_back({nxt,++tp});
            rt = nxt;
            sz = i;
        }
    }
    int nxt = ++tp;
    if(sz) ans.push_back({nxt, rt});
    for(int j=1;j<=n-sz-1;++j) ans.push_back({nxt,++tp});
    for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
}