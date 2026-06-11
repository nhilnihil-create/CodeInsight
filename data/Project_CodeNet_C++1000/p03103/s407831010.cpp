#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(){
    int n,m;
    cin >> n >> m;
    pair<int,int>p[100009];
    rep(i,n){
        cin >> p[i].first >> p[i].second;
    }
    int sum=0;
    int now=0;
    ll ans=0;
    sort(p,p+n);

    while(sum<m){
        ans+=p[now].first;
        p[now].second-=1;
        if(p[now].second==0)now++;
        sum++;
    }

    cout << ans;

    return 0;
}