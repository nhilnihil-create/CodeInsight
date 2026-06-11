//url:
//problem name: 

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

bool ok(string S) {
    bool ok1 = false;
    bool ok2 = false;
    bool ok3 = false;
    for(char c : S) {
        if(c == '3') ok1 = true;
        if(c == '5') ok2 = true;
        if(c == '7') ok3 = true;
    }
    if(ok1 && ok2 && ok3) return true;
    else return false;
}

int main() {
    int N;
    cin >> N;
    queue<string> que;
    que.push("3");
    que.push("5");
    que.push("7");
    ll ans = 0;
    while(1) {
        string v = que.front();
        que.pop();
        if(stol(v) > N) break;
        if(ok(v)) ans++;
        que.push(v+'3');
        que.push(v+'5');
        que.push(v+'7');
    }
    cout << ans << endl;
}