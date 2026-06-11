#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 

int main() {
    string s,t;
    cin >> s>>t;
    bool ok = false;
    if (s==t){ cout << "Yes" << endl;
              return 0;}
    rep(i,s.size()){
    if(t==s.substr(i,s.size()-1)+s.substr(0,i)){
        ok = true;
    }
    }
    if(ok) cout << "Yes" <<endl;
    else cout << "No" <<endl;
 }
