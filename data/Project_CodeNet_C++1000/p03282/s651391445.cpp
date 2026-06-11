#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
const int mod = 1000000007;

int main() {
    string s;
    cin >> s;
    int k;
    cin>>k;
    if(k<=s.size()){
    bool ok = true;
    rep(i,k){
        if(s[i]!='1') ok = false;
    }
    if(ok){
        cout << 1 << endl;
        return 0;
    }
    else{
        rep(i,k){
            if(s[i]!='1'){
                cout << s[i] <<endl;
                return 0;
            }
        }
    }
    }
    else{
        rep(i,s.size()){
            if(s[i]!='1') {
                cout << s[i] <<endl;
                return 0;
            }
        }
        cout << 1 <<endl;
    }

}