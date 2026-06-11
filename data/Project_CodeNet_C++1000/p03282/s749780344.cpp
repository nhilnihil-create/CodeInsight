#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    string s;
    ll k;
    cin >> s >> k;

    bool a(true);
    rep(i,k){
        if(s[i]!='1'){
            if(k==1 || s.size()==1)    cout << s[0] << endl;
            else if(i<=k)    cout << s[i] << endl;
            else    cout << 1 << endl;
            a = false;
            break;
        }
    }
    if(a)   cout << 1 << endl;

    return 0;
}