#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n,k;
vector<int> l;
vector<int> r;
int ans = 1;

void input(){
    cin >> n >> k;
}

void solve(){
    rep(i,n){
        if (ans+k <= ans*2){
            ans += k;
        } else {
            ans *= 2;
        }
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}