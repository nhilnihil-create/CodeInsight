#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    string s, t; cin >> s >> t;

    // 同じ文字は同じ文字に変換されるのを
    // s -> t, t -> sで調べる
    V<char> v1(100), v2(100);
    for(int i = 0; i < s.size(); i++){
        if(v1[t[i] - 'a'] == 0){
            v1[t[i] - 'a'] = s[i];
        }else if(v1[t[i] - 'a'] != s[i]){
            cout << "No" << endl;
            return 0;
        }
        if(v2[s[i] - 'a'] == 0){
            v2[s[i] - 'a'] = t[i];
        }else if(v2[s[i] - 'a'] != t[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
