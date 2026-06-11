#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n; cin >> n;

    int ans = 1;

    rep(i,n){
        if((i+1)*(i+1) <= n) ans = (i+1)*(i+1);
        else break;
    }

    cout << ans << endl;
}