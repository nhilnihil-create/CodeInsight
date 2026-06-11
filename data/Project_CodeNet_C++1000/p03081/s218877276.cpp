#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<char> t(q);
    vector<char> d(q);
    for (int i = 0; i < q; i++) cin >> t[i] >> d[i];
    int ok = n;
    int ng = - 1;
    while (abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        int now = mid;
        bool flag = true;
        for (int i = 0; i < q; i++){
            if (t[i] == s[now]){
                if (d[i] == 'L') now--;
                else now++;
            }
            if (now < 0) flag = false;
        }
        if (flag) ok = mid;
        else ng = mid;
    }
    int left = ok;
    ok = - 1;
    ng = n;
    while (abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        int now = mid;
        bool flag = true;
        for (int i = 0; i < q; i++){
            if (t[i] == s[now]){
                if (d[i] == 'L') now--;
                else now++;
            }
            if (now >= n) flag = false;
        }
        if (flag) ok = mid;
        else ng = mid;
    }
    int right = ok;
    cout << right - left + 1 << endl;
}