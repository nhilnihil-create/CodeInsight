#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    string S; cin >> S;
    int ans = 0;

    int l = 0, r = S.size()-1;
    while(l < r){
        if(S[l] == S[r]) {
            l++;
            r--;
        }
        else{
            if(S[l] == 'x'){
                ans++;
                l++;
            }
            else if(S[r] == 'x'){
                ans++;
                r--;
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;

}