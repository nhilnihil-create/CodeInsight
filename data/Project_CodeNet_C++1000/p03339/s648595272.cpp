#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int change=0, ans;
    for (int i=0; i<n; i++){ if (s[i] == 'E') change += 1;}
    if (s[0] == 'E') ans = change-1;
    else ans = change;
    for (int leader=1; leader < n; leader++){
        if (s[leader-1] == 'E') change += -1;
        else change += 1;
        if (s[leader] == 'E') ans = min(ans, change-1);
        else ans = min(ans, change);
    }
    cout << ans << endl;
    return 0;
}