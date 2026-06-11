#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    vector<int> beki(31);
    rep(i,31) beki[i]=pow(2,i);
    
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    
    int ans=0;
    while(sz(a)>1){
        int key=a.back();
        a.pop_back();
        rrep(i,31){
            if(beki[i]-key<1) continue;
            int x=lower_bound(all(a),beki[i]-key)-a.begin();
            if(x<sz(a) && a[x]==beki[i]-key){
                a.erase(a.begin()+x);
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    
}

