#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int n; cin >> n;
    //if(n < 105) cout << 0 << endl;
    int ans, num;
    ans = 0;
    for(int i = 1; i < n + 1; i = i + 2){
        num = 0;
        for(int j = 1; j < i + 1; j = j + 2){
            if(i % j == 0) num++;
            if(num == 9) break;
        }
        if(num == 8) ans++;
    }
    cout << ans << endl;
}