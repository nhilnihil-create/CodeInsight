#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;cin >> n;
    vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];
    int m;cin >> m;
    vector<int> t(m);for(int i=0;i<m;i++) cin >> t[i];
    if(n<m){
        cout << "NO" << endl;
        return 0;
    }
    sort(a.begin(),a.end());
    sort(t.begin(),t.end());
    int i=-1;
    bool ans=true;
    for(int j = 0; j < m; j++) {
        while(i<n){
            i++;
            if(i<n && t[j]==a[i]) break;
        }
        if(i>=n) {
            ans = false;
            break;
        }
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}