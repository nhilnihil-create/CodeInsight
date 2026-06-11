#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> wf(n);
    for(int i = 0; i < n; i++){
        if(s[i] == 'W') wf[i]++;
    }
    for(int i = 0; i < n - 1; i++){
        wf[i+1] += wf[i];
    }
    vector<int> eb(n);
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == 'E') eb[i]++;
    }
    for(int i = n - 1; i > 0; i--){
        eb[i-1] += eb[i];
    }
    int ans = eb[1];
    for(int i = 1; i < n - 1; i++){
        ans = min(ans, wf[i-1] + eb[i+1]);
    }
    ans = min(ans, wf[n-2]);
    cout << ans << endl;
    return 0;
}