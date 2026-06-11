#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    string S;
    cin >> S;
    int ans = 0;
    int i = 0;
    int j = S.size()-1;
    while(i < j) {
        if(S[i] == S[j]) {
            i++;
            j--;
            continue;
        }
        if(S[i] == 'x') {
            ans++;
            i+=1;
        }
        else if(S[j] == 'x') {
            ans++;
            j-=1;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}