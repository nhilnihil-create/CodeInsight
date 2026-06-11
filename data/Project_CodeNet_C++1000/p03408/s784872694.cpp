#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> add, sub;

    int n; cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        add[s[i]]++;
    }
    int m; cin >> m;
    vector<string> t(m);
    for(int i=0; i<m; i++){
        cin >> t[i];
        sub[t[i]] ++;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int tmp = add[s[i]] - sub[s[i]];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}    