#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string S; cin >> S;
    int s = S.size();
    int cnt0 = 0;
    int cnt1 = 0;
    rep(i, s){
        if(S[i] == '0'){
            cnt0++;
        } else {
            cnt1++;
        }
    }
    int ans = min(cnt0, cnt1);
    ans *= 2;

    cout << ans << endl;


    return 0;
}