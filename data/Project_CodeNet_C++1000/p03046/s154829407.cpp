#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using grid = vector<vector<int>>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = 1<<30;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    ll M,K;
    cin>>M>>K;
    if((1LL<<M)<=K)cout<<-1<<endl;
    else if(M==0){
        if(K==0) cout<<0<<" "<<0<<endl;
        else cout<<-1<<endl;
    }
    else if(M==1) {
        if(K==0) cout<<0<<" "<<0<<" "<<1<<" "<<1<<endl;
        else cout<<-1<<endl;
    }
    else {
        vector<ll> ans(1LL<<(M+1),0);
        ans[0] = K;
        ll N = (1LL<<(M+1));
        for(ll i = 1; i<=(1LL<<(M))-1; i++){
            if(i<=K) ans[i] = ans[N-i] = i-1;
            else ans[i] = ans[N-i] = i;
        }
        ans[(1LL<<M)]=K;
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }
}