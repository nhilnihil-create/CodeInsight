#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1<<29;
using Graph = vector<vector<int>>;
int main() {
    int A[4];
    for (int i=0;i<4;++i){
        char x; cin >> x;
        A[i] = x-'0';
    }    
    int tmp;
    string ans;
    for (int bit=0; bit<(1<<3); ++bit){
        tmp = A[0];
        ans = to_string(A[0]);
        for (int i=0;i<3;++i){
            if (bit&(1<<i)) {
                tmp += A[i+1];
                ans += '+'; 
            }else {
                tmp -= A[i+1];
                ans += '-';
            }
            ans += ('0'+A[i+1]);
        }
        if (tmp==7) {
            cout << ans << "=7" << endl;
            break;
        }
    }
    return 0;
}