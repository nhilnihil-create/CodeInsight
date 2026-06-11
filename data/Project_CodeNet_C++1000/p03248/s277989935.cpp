#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    s = "." + s;
    bool exist = true;
    if(s[1] == '0' || s[n] == '1') exist = false;
    for(int i = 1; i < n; ++i){
        if(s[i] != s[n-i]) exist = false;
    }
    if(!exist){
        cout << -1 << endl;
        return 0;
    }
    s[n] = '1';
    queue<int> ones;
    for(int i = 1; i <= n; ++i){
        if(s[i] == '1') ones.push(i);
    }
    for(int i = 1; i < n; ++i){
        if(i == ones.front()) ones.pop();
        cout << i << " " << ones.front() << endl;
    }
    return 0;
}