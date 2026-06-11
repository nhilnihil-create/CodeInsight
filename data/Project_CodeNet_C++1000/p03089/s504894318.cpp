/**
*    author:  souzai32
*    created: 07.08.2020 23:25:51
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    vector<int> ans(n);
    bool check=true;

    rep(i,n){
        for(int j=n-i; j>=0; j--){
            if(j==0) {
                check=false;
                break;
            }
            if(a.at(j-1)==j){
                ans.at(i)=j;
                a.erase(a.begin()+(j-1));
                break;
            }
            if(!check) break;
        }
        //cout << i << endl;
    }

    reverse(ans.begin(),ans.end());
    if(check) rep(i,n) cout << ans.at(i) << endl;
    else cout << -1 << endl;

    return 0;
}