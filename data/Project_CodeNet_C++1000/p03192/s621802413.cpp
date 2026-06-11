/*
      author : nishi5451
      created: 12.08.2020 00:18:04
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int ans = 0;
    rep(i,4) if(s[i]=='2') ans++;
    cout << ans << endl;
    return 0;
}