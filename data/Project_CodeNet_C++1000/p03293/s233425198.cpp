#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s, t;
    cin >> s >> t;
    rep(i,100) {
        char temp = s.back();
        s.pop_back();
        s.insert(0, 1, temp);
        if(s==t){ cout << "Yes" << endl; return 0;}
    }
    cout << "No" << endl;
    return 0;
}