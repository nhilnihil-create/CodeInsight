#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF = numeric_limits<long long>::max();
#define intf int_fast64_t
int main(){
    string s;
    cin >> s;

    rep(i,s.size()){
        if(i==3){
            cout << 8;
            continue;
        }
        cout << s[i];
    }
}