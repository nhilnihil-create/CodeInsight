#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<int>;
using vv = vector<v>;

int main(){
    string s;
    cin >> s;
    
    int ans = 753;
    for(int i=0; i<s.size()-2; i++){
        int now = 0;
        for(int j=0; j<3; j++){
            now *= 10;
            now += s[i+j]-'0';
        }
        ans = min( abs(now-753), ans );
    }
    cout << ans << endl;
    return 0;
}