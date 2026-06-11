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

bool acgt(char c){
    return c == 'A' || c == 'C' || c == 'G' || c == 'T';
}

int main(){
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        int buf = 0;
        for(int j = i; j < n; j++){
            if(acgt(s[j])) ++buf;
            else break;
        }
        ans = max(ans, buf);
    }
    cout << ans << endl;
}