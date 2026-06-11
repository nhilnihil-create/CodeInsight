#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    string s;
    cin >> s;
    string a[2] = {"A",""};
    bool can = false;
    rep(i,1 << 4){
        string t = a[1&(i>>0)] + "KIH" + a[1&(i>>1)] + "B" + a[1&(i>>2)] + "R" + a[1&(i>>3)];
        if(s == t) can = true;
    }
    cout << (can? "YES" : "NO") << endl;
    return 0;
}