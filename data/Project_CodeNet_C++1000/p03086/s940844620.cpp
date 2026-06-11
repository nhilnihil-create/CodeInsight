#include <iostream>
#include <string>
#include <map>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    string S;
    cin >> S;

    string T = "ATCG";

    int ans, now;
    ans = now = 0;
    rep(i, S.size()){
        bool isATCG = false;
        rep(j, T.size()) {
            if (S[i] == T[j]) isATCG = true;
        }
        if (!isATCG) 
            now = 0;
        else {
            now++;
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}