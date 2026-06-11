#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    string s; cin>>s;
    ll k; cin>>k;
    rep(i, k){
        if(i >= s.size()) break;
        if(s[i] != '1'){
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << '1' << endl;
    return 0;
}