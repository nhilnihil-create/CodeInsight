#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    int n,m;cin>>n>>m;
    vector <int> x(m);
    int test= 0;
    rep(i,m){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    vector<int> y(m);
    rep(i,m-1){
        y[i]=abs(x[i]-x[i+1]);
    }
    sort(y.begin(),y.end());
    ll ans = 0;
    for(int i = 0;i<m-n+1;++i){
        ans += y[i];

    }
    cout<<ans<<endl;

}
