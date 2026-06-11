#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;

//入力
ll d,g;
vector<ll>p,c;

int main(){
    cin >> d >> g;
    p.resize(d);
    c.resize(d);
    rep(i,d)cin>>p[i]>>c[i];
    ll ans = INF;
    for(int bit=0;bit<(1<<d);bit++){
        ll solved = 0;
        ll score = 0;
        priority_queue<ll>pq;
        rep(i,d){
            if((bit>>i)&1){
                solved+=p[i];
                score += 100*(i+1)*p[i]+c[i];
            }
            else{
                rep(j,p[i]){
                    pq.push(100*(i+1));
                }
            }
        }
        while(score<g){
            score+=pq.top();pq.pop();
            solved++;
        }
        chmin(ans,solved);
    }
    cout << ans << endl;
    
    return 0;
}
