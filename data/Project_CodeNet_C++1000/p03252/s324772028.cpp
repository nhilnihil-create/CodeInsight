#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S,T;
    cin >> S >> T;
    bool ok = true;
    map<char,char> ma, ima;
    for (int i = 0; i < S.size(); ++i) {
        char s = S[i], t = T[i];
        if (ma.count(s)) if (ma[s] != t) ok = false;
        if (ima.count(t)) if (ima[t] != s) ok = false;
        ma[s] = t; ima[t] = s;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    /*
    // 嘘解法
    vector<int> Smoji(26),Tmoji(26);
    rep(i,S.size()){
        Smoji[S[i]-'a']++;
        Tmoji[T[i]-'a']++;
    }
    sort(Smoji.begin(),Smoji.end());
    sort(Tmoji.begin(),Tmoji.end());
    rep(i,26){
        if(Smoji[i]!=Tmoji[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    */
    return 0;
}