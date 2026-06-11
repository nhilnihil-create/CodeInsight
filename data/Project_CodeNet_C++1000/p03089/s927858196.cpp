#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    int n;cin >> n;
    vector<int> b(n);for(int i=0;i<n;i++) cin >> b[i];
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = b.size()-1; j >=0; j--) {
            if(b[j]==j+1){
                ans.push_back(b[j]);
                b.erase(b.begin()+j);
                break;
            }
        }
    }
    if(ans.size()!=n){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++) {
        cout << ans[n-1-i] << endl;
    }

    return 0;
}