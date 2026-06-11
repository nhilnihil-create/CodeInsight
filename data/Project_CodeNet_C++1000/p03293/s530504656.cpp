#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    string s,t;
    cin >> s >> t;

    rep(i,s.size()+10){
        char c = s[s.size()-1];
        s = c + s;
        s.erase(s.size()-1);

        if(s==t){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}