#include<bits/stdc++.h>
using namespace std;
int main(){
        string s; cin >> s;
        long long int k; cin >> k;
        if (s[0] != '1') cout << s[0] << endl;
        else{
            int one_cnt = 0;
            for (auto x : s){
                if (x == '1') ++one_cnt;
                else break;
            }
            if (k <= one_cnt) cout << 1 << endl;
            else cout << s[one_cnt] << endl;
        }
    return 0;
}