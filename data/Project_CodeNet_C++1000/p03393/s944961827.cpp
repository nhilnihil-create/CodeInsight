#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string S;
    cin >> S;

    if(S == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }

    ll n = S.size();
    map<char, bool> r;
    for(auto s : S){
        r[s] = true;
    }

    if(n < 26){
       for(char c = 'a'; c <= 'z'; c++){
           if(r.count(c) == 0){
               S.push_back(c);
               cout << S << endl;
               return 0;
           }
       } 
    }else{
        for(ll k = n-2; k >= 0; k--){
            char c = S[k];
            char mn = 'z' + 1;
            for(ll i = k+1; i < n; i++){
                if(S[i] > c) mn = min(S[i], mn);
            }
            if(mn < 'z' + 1){
                rep(j, 0, k) cout << S[j];
                cout << mn << endl;
                return 0;
            }
        }
    }

    return 0;
}