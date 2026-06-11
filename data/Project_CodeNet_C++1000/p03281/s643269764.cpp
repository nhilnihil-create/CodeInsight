#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------
 
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
 
bool check(int i) {
    int tmp = 1;
    for(int a = 1; a <= i / 2; a++) {
        if(i % a == 0) {
            tmp++;
        }
    }
    if(tmp == 8) {
        return true;
    }else return false;
}
 
 
int main(void) {
    int n;
    cin >> n;
 
    int ans = 0;
    for(int i = 1; i <= n; i += 2) {
        if(check(i)) {
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}