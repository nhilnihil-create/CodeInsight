#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    int n = s.size();
    int m = t.size();
    bool ans = true;
    if(n < m){
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                ans = false;
                break;
            }
        }
        if(ans){
            cout << "Yes\n";
            return 0;
        }
    }
    ans = false;
    for(int i = 0; i < min(n, m); i++){
        if(s[i] == t[i]) continue;
        else if(s[i] < t[i]){
            ans = true;
            break;
        } else {
            ans = false;
            break;
        }
    }
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}