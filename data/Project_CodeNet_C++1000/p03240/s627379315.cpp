#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);
const int MAX=200010;


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> p(n);
    rep(i,n) cin >> p[i].second.first >> p[i].second.second >> p[i].first;
    sort(p.begin(),p.end(),greater<>());
    rep(i,101) {
        rep(j,101) {
            bool flag=1;
            int tmph=abs(p[0].second.first-i)+abs(p[0].second.second-j)+p[0].first;
            rep(k,n) {
                int h=tmph-abs(p[k].second.first-i)-abs(p[k].second.second-j);
                if (max(h,0)!=p[k].first) flag=0;
            }
            if (flag) {
                cout << i << ' ' << j << ' ' << tmph << endl;
                return 0;
            }
        }
    }

    return 0;
}
