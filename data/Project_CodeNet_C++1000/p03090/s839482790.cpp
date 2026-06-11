#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<P> ans;
    int a = n-n%2;
    for(int i = 1; i <= a; i++){
        for(int j = i+1; j <= a; j++){
            if(i + j != a+1)ans.push_back({i, j});
        }
    }
    for(int i = 1; i <= (n%2)*(n-1); i++)ans.push_back({i, n});
    cout << ans.size() << endl;
    rep(i, ans.size())cout << ans[i].first << " " << ans[i].second << endl;
}  