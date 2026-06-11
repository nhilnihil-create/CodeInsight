/**
*    author:  souzai32
*    created: 08.08.2020 00:00:45
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> AC(n);
    int countAC=0;

    rep(i,n-1){
        if(s.at(i)=='A'&&s.at(i+1)=='C') countAC++;
        AC.at(i)=countAC;
    }
    AC.at(n-1)=AC.at(n-2);
    //rep(i,n) cout << AC.at(i) << endl;

    int l,r;
    int ans;
    rep(i,q){
        cin >> l >> r;
        l--;
        r--;
        ans=AC.at(r)-AC.at(l);
        if(l!=n-1){
            if(s.at(l)=='A'&&s.at(l+1)=='C') ans++;
        }
        if(r!=n-1){
            if(s.at(r)=='A'&&s.at(r+1)=='C') ans--;
        }
        cout << ans << endl;
    }
    

    return 0;
}