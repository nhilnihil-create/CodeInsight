#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;
int main(){
    int n;
    cin >> n;
    vector<P> ve;
    rep(i,n){
        int b;
        cin >> b;
        ve.emplace_back(b,i-b+1);
    }
    vector<int> ans;
    rep(i,n){
        for(int j=n-1-i; j>=0; j--){
            if(ve[j].second==0){
                for(int k=j+1; k<ve.size(); k++){
                    ve[k].second--;
                }
                ans.push_back(ve[j].first);
                ve.erase(ve.begin()+j);
                break;
            }
        }
        if(ans.size()!=i+1){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(),ans.end());
    rep(i,n) cout << ans[i] << endl;

    return 0;
}