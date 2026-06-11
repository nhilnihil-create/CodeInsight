/**
*    author:  souzai32
*    created: 15.08.2020 01:38:51
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> white(n+1),black(n+1);
    for(int i=1; i<n+1; i++){
        if(s.at(i-1)=='#') black.at(i)++;
        if(i!=n) black.at(i+1)=black.at(i);
    }
    reverse(all(s));
    for(int i=1; i<n+1; i++){
        if(s.at(i-1)=='.') white.at(i)++;
        if(i!=n) white.at(i+1)=white.at(i);
    } 

    int ans=2e5;
    for(int i=0; i<=n; i++) ans=min(ans,black.at(i)+white.at(n-i));
    cout << ans << endl;
    return 0;
}