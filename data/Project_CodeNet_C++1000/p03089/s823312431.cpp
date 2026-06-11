#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int n;
bool flag;
vector<int> ans;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    while(!a.empty()) {
        flag = false;
        for(int i = a.size() - 1; i >= 0; i--) {
            if(a[i] == i) {
                a.erase(a.begin() + i);
                ans.pb(i + 1);
                flag = true;
                break;
            }
        }
        if(!flag) {
            ans.clear();
            ans.pb(-1);
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans) cout << i << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}