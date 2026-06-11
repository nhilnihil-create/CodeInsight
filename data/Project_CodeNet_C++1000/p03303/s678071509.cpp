#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; int w; cin >> S >> w;
    string ans="";
    for (int i=0;i<S.size();++i){
        if (i%w==0) ans+=S[i];
    }
    cout << ans << '\n';
}