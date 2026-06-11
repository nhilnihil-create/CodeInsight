#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    vector<int> t(3);
    rep(i,3) cin >> t[i];
    int ans = 1e9;
    do{
        int c = abs(t[0]-t[1]) + abs(t[1]-t[2]);
        ans = min(ans, c);
    }while(next_permutation(t.begin(), t.end()));
    cout << ans << endl;
}