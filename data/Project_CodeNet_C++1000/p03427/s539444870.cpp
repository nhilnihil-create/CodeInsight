#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int ctoi(char c){
    switch (c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

int main(){
    string S;
    cin >> S;
    int len = S.size();
    int ans = 0;
    bool all_9 = true;
    rep(i,len - 1){
        if (S[i + 1] != '9'){
            all_9 = false;
        }
    }
    if (all_9){
        rep(i,len){
            ans += ctoi(S[i]);
        }
    }
    else{
        ans += (ctoi(S[0]) - 1);
        rep(i,len - 1){
            ans += 9;
        }
    }
    if (len == 1) cout << ctoi(S[0]) << endl;
    else cout << ans << endl;
}

