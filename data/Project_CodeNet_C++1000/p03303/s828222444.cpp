#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9+7;


int main(){
    string S, ans = "";
    ll w;
    cin >> S >> w;
    for(int i = 0; i < S.size(); i++){
        if(i*w >= S.size()) break;
        ans += S[i*w];        
    }
    cout << ans << endl;
}