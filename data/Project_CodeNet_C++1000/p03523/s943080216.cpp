#include <bits/stdc++.h>
using namespace std;

int main(){
    string ans = "AKIHABARA";
    string s;
    cin >> s;
    if (s.size() > 9){
        cout << "NO" << endl;
        return 0;
    }
    int now = 0;
    for (int i = 0; i < ans.size(); i++){
        if (i - now > s.size()){
            cout << "NO" << endl;
            return 0;
        }
        if (i - now == s.size() || s[i - now] != ans[i]){
            if (ans[i] == 'A') now++;
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (s.size() + now != 9) cout << "NO" << endl;
    else cout << "YES" << endl;
}