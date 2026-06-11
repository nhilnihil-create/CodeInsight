#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s; cin >> s;
    int len = s.length();
    int c = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == 'o') c++;
    }
    if(c+(15-len) >= 8) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}