#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    ll x,y,cnt=1;
    cin >> x >> y;
    while(1){
        x*=2;
        if(x<=y) ++cnt;
        else break;
    }
    cout << cnt << "\n";
    return 0;
}