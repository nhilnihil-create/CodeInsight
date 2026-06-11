#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> res;
    int dame=n;
    if(n%2==1) dame--;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=i || j==dame) continue;
            res.push_back({i,j});
        }
        dame--;
    }

    cout<<res.size()<<endl;
    for(auto p : res) cout<<p.first<<" "<<p.second<<endl;
}