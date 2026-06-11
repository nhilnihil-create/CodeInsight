#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int N,K;
    cin>>N>>K;
    vector<int> h(N);
    rep(i,N){
        cin>>h[i];
    }
    sort(all(h));
    //幅Kで見て探索
    int ans=1000000000;
    rep(i,N-K+1){
        ans=min(ans,h[i+K-1]-h[i]);
    }
    cout << ans << endl;
    return 0;
}