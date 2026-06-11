#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    int64_t K;
    int pos = 0;
    int ans;
    cin >> S >> K;

    // 2が5000 * 10^12 => 5 * 10^15日後には
   
    ans = 1;
    for(int i=0;i<K;i++) {
        if(S[i] != '1') {
            ans = S[i]-'0';
            break;
        }     
    }

    cout << ans << endl;
    
    return 0;
}
