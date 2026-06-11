#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    ll N,H;
    cin>>N>>H;
    int ans = 0;
    vector<P> v(2*N);
    rep(i,N){
        ll x,y;
        cin>>x>>y;
        v[2*i] = make_pair(x,0);
        v[2*i+1] = make_pair(y,1);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int p = 0;
    while(H>0){
        if(v[p].second==1){
            H-=v[p].first;
            p++;
            ans++;
        }
        else{
            ans+=((H-1)/v[p].first)+1;
            H=0;
        }
    }
    cout<<ans<<endl;
}