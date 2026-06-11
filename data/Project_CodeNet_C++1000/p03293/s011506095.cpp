#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    rep(i,n){
        bool flag = true;
        rep(j,n) if(s[(i+j)%n] != t[j]) flag = false;
        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}