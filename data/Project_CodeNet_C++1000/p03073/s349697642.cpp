#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string S; cin >> S;
    int s = S.size();
    int s1 = 0;
    int s0 = 0;
    rep(i, s){
        if(i % 2 == 0){
            if(S[i] == '0'){
                s1++;
            } else {
                s0++;
            }
        } else {
            if(S[i] == '0'){
                s0++;
            } else {
                s1++;
            }
        }
    }

    int ans = min(s0, s1);
    cout << ans << endl;

    return 0;
}