#include<bits/stdc++.h>
using namespace std;
int main(){
        string s; cin >> s;
        long long int k; cin >> k;
        int one_cnt = 0;
        for (auto x : s){
            if (x == '1') ++one_cnt;
            else break;
        }
        if (one_cnt >= k) cout << s[one_cnt-1] << endl;
        else cout << s[one_cnt] << endl;
    return 0;
}
