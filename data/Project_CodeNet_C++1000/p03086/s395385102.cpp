#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    string s;
    cin >> s;
    int res = 0;
    rep(i, s.size()){
        int l = 0;
        rep(j, s.size() - i){
            if(s[i+j] == 'A' || s[i+j] == 'T' || s[i+j] == 'C' || s[i+j] == 'G'){
                ++l;
            }else{
                break;
            }
        }
        res = max(res, l);
    }
    cout << res << endl;
}
