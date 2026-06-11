#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<int> x(n);
    rep(i,n) cin>>x[i];
    auto X=x;
    sort(x.begin(),x.end());
    rep(i,n){
        auto itr=lower_bound(x.begin(),x.end(),X[i]);
        int k=itr-x.begin();
        if(k>=n/2)cout<<x[n/2-1]<<endl;
        else cout<<x[n/2]<<endl;
    }
}