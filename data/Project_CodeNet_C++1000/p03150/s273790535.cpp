#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    string S;
    cin >> S;
    rep(i, 0, 7){
        string S2 = S.substr(0, i) + S.substr(S.size()-7+i, 7-i);
        if(S2 == "keyence"){
            cout << "YES" << endl;
            return 0;
        }
    }
     cout << "NO" << endl;
}