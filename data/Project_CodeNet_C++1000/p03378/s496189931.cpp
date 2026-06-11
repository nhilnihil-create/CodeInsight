#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i,m) cin >> a.at(i);
    int cost1=0;
    for(int i=x;i<=n;i++){
        rep(j,m){
            if(a.at(j)==i)cost1++;
        }
    }
    int cost2=0;
    for(int i=x;i>=0;i--){
        rep(j,m){
            if(a.at(j)==i)cost2++;
        }
    }
    cout << min(cost1,cost2) << endl;
}