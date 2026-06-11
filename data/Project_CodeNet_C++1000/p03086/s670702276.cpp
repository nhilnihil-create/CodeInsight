#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    int ans = 0;
    int S_len = S.size();
    for (int i=0; i<S_len; ++i){
        int cnt = 0;
        for (int j=i; j<S_len; ++j){
            if (S[j]=='A' || S[j]=='G' || S[j]=='C' || S[j]=='T'){
                cnt += 1;
            }else{
                break;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}