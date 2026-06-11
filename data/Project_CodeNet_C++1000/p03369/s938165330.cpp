#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    map<char ,int > mp;
    rep(i,3){
        char c; cin >> c;
        mp[c]++;
    }

    cout << 700 + 100 * mp['o'] << endl;

    return 0;
}