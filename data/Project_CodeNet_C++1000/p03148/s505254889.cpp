#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
bool chmin(ll & a, ll  b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll & a, ll b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N=500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    cin >> n>>k;
    vector<PP> VP;
    multiset<PP> VP1;
    vl used(200000,0);

    rep(i,n){
        cin>>x>>y;
        VP.push_back({y,x});
    }

    sort(all(VP));
    reverse(all(VP));

    
    rep(i,k){
        a+=VP[i].first;
        if(used[VP[i].second]==0){
            used[VP[i].second]++;
            b++;
        }
        else VP1.insert(VP[i]);
    }

    ans=a+b*b;

    for(ll i=k;i<n;i++){
        if(used[VP[i].second]==0&&!VP1.empty()){
        	used[VP[i].second]++;
            auto ite=VP1.begin();
            a-=(*ite).first;
            a+=VP[i].first;
            VP1.erase(ite);
            b++;
            ans=max(ans,a+b*b);
        }
    }

    cout<<ans<<endl;
}