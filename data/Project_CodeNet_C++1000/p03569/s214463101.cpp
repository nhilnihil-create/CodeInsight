#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string t = "";
    vector<int> cnt;
    bool flag = true;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] != 'x') {
            t += s[i];
            if (flag){
                cnt.push_back(tmp);
                tmp = 0;
                flag = false;
            }
            else cnt.push_back(0);
        }
        else {
            if (flag) tmp++;
            else {
                tmp = 1;
                flag = true;
            }
        }
    }
    cnt.push_back(tmp);
    flag = true;
    for (int i = 0; i < t.size(); i++){
        if (t[i] != t[t.size() - i - 1]) flag = false;
    }
    if (!flag){
        cout << - 1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < cnt.size(); i++) ans += abs(cnt[i] - cnt[cnt.size() - i - 1]);
    cout << ans / 2 << endl;
}