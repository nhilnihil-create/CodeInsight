#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;


int main() {
    string S;
    cin >> S;

    if(S == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }
    map<char, int> mp;
    for(char c: S){
        mp[c]++;
    }
    if(mp.size() != 26){
        for(char c = 'a'; c <= 'z'; c++){
            if(!mp.count(c)){
                cout << S << c << endl;
                return 0;
            }
        }
    }
    string T = S;
    next_permutation(S.begin(), S.end());
    for(int i = 0; i < S.size(); i++){
        if(S[i] == T[i]){
            cout << S[i];
            continue;
        }
        cout << S[i] << endl;
        return 0;
    }

}
