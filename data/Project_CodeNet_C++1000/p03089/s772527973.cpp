#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    int n; cin >> n;
    vector<int> b(n);
    vector<int> ans;
    vector<int>::iterator it;

    rep(i,n) cin >> b[i];

    it = ans.begin();

    rep(i,n){
        if(b[i] > ans.size()+1){
            cout << -1;
            return 0;
        }else{
            ans.insert(ans.begin()+b[i]-1,b[i]);
        }
    }

    rep(i,ans.size()){
        cout << ans[i] << endl;
    }


    return 0;
}
