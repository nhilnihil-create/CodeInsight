/**
*    author:  souzai32
*    created: 13.08.2020 17:19:10
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    string s;

    int a=0,b=0,ab=0;
    int ans=0;
    rep(i,n){
        cin >> s;
        if(s.at(0)=='B' && s.at(s.size()-1)=='A') ab++;
        else if(s.at(0)=='B') b++;
        else if(s.at(s.size()-1)=='A') a++;
        rep(j,s.size()-1){
            if(s.at(j)=='A' && s.at(j+1)=='B') ans++;
        }
    }

    if(max(a,b)) ans+=min(a,b)+ab;
    else ans+=max(ab,1)-1;

    cout << ans << endl;

    return 0;
}
