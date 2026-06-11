#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const ll INF=2e15;
const double PI=acos(-1);

vector<P> vectorCnt(vector<int> a) {
    sort(a.begin(),a.end());
    int n=a.size();
    vector<pair<int,int>> b;
    int cnt=1;
    rep(i,n-1) {
        if (a[i+1]!=a[i]) {
            b.push_back({cnt,a[i]});
            cnt=1;
        } else {
            ++cnt;
        }
    }
    b.push_back({cnt,a[n-1]});
    return b;
}

int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<int> a(n/2),b(n/2);
    rep(i,n) {
        if (i%2==0) cin >> a[i/2]; 
        else cin >> b[i/2];
    }
    vector<P> aa=vectorCnt(a);
    vector<P> bb=vectorCnt(b);
    aa.push_back({0,0});
    bb.push_back({0,0});
    sort(aa.begin(),aa.end(),greater<>());
    sort(bb.begin(),bb.end(),greater<>());
    int ans;
    if (aa[0].second!=bb[0].second) {
        ans=n-(aa[0].first+bb[0].first);
    } else {
        int ans1=n-(aa[0].first+bb[1].first);
        int ans2=n-(aa[1].first+bb[0].first);
        ans=min(ans1,ans2);
    }
    cout << ans << endl;
    


    return 0;
}
