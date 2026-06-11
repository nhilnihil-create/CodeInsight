#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v.at(i);
    vector<int> c(n);
    rep(i,n) cin >> c.at(i);
    int ans=0;
    rep(i,n){
        if(v.at(i)>c.at(i))ans+=v.at(i)-c.at(i);
    }
    cout << ans << endl;
}
