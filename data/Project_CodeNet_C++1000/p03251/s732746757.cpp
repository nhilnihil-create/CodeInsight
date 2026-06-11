#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,m,x,y,res;
    cin>>n>>m>>x>>y;
    vector<int> X(n),Y(m);
    rep(i,n) cin>>X[i];
    rep(i,m) cin>>Y[i];
    sort(Y.begin(),Y.end());
    sort(X.begin(),X.end());
    res=Y[0];
    if (X[n-1]<res&&x<res&&res<=y) {
        cout<<"No War"<<endl;
    } else {
        cout<<"War"<<endl;
    }
}   
