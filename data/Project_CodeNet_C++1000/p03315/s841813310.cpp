/*
      author : nishi5451
      created: 11.08.2020 20:40:57
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(auto a : s){
        if(a=='+') ans++;
        else ans--;
    }
    cout << ans << endl;
    return 0;
}