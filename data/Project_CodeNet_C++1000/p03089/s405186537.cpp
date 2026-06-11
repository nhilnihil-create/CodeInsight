#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n;cin >> n;
    vi b(n);
    rep(i,n) cin >> b[i];
    vi ans;
    rep(i,n){
        for(int j=b.size()-1;j>=0;j--){
            if(b[j]==j+1){
                ans.push_back(j+1);
                b.erase(b.begin() + j);
                break;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    if(ans.size()!=n){
        cout << -1 << endl;
    }else{
        rep(i,n) cout << ans[i] << endl;
    }
}