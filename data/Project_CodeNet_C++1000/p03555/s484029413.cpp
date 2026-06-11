#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 10**9

int main() {
    string s,t;
    bool flag=true;
    cin >> s >> t;
    rep(i,3){
        if (s.at(i)!=t.at(2-i)){
            flag = false;
            break;
        } 
    }
    if (flag){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}