#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    string s;cin >> s;
    ll k;cin >> k;
    ll one=0;
    char x;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '1'){
            x=s[i];
            break;
        }
        else one++;
        
    }

    if(k<=one) cout << 1 << endl;
    else cout << x << endl;
    

    return 0;
}