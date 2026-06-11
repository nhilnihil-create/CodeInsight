#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,m; cin >> n >> m;
    vector<P> vec(m);
    rep(i,m) {
        int a,b; cin >> a >> b;
        a--;b--;
        vec[i] = P(b,a);
    }
    sort(ALL(vec));
    int ans = 0;
    int now = 0;
    int end = 0;
    while(now <= m-1){
        if(end <= vec[now].second){
            ans++;
            end = vec[now].first;
        }
        now++;
    }
    cout << ans << endl;
}