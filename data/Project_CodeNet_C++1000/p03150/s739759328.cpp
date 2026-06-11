#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if(s=="keyence") {cout << "YES" << endl; return 0;}
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= s.size(); ++j) {
            string temp = s;
            temp.erase(i,j);
            if(temp=="keyence"){
                cout << "YES" << endl;
                return 0;
            } 

        }
    }
    cout << "NO" << endl;
    return 0;
}