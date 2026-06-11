#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(int i=cc;i>=n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
int n;
vector<int> a;
void solve(){
    vector<int>ans;
    rep(i, 0, n){
        int k = -1;
        rrep(j, a.size()-1, 0){
        if(a[j] == j){
            k = j;
            break;
        }
        }
        if(k == -1){
            cout << -1 << endl;
            return;
        }
        ans.push_back(k+1);
        a.erase(a.begin()+k);
    }
    reverse(ans.begin(), ans.end());
    rep(i, 0, n){
        cout << ans[i] << endl;
    }
}

int main(){
    cin >> n;
    a.resize(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }
    solve();
}