#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    rep(i,n) {
        cin>>x[i];
        y[i]=x[i];
    }
    sort(y.begin(),y.end());
    rep(i,n) {
        if (x[i]<=y[n/2-1]) cout<<y[n/2]<<endl;
        else cout<<y[n/2-1]<<endl;
    }
}
