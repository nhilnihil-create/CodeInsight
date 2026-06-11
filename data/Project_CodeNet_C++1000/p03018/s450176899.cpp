#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
int main() {
    string S;
    cin >> S;
    long long res = 0;
    int cnt = 0;
    rep(i, 0, S.size()-1){
        if(S[i] == 'A'){
            cnt++;
        } else if (S[i] == 'B') {
            if (S[i+1] == 'C'){
                res += cnt;
                i++;
            } else {
                cnt =0;
            }
        } else {
            cnt = 0;
        }
    }
    cout << res << endl;
    return 0;
}
