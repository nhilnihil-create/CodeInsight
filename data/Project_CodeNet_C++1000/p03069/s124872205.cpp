#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;cin >> n;
    string s;
    cin >> s;
    int temp = 0;
    rep(i,n) if(s[i]=='.') temp++;
    int ans = temp;
    rep(i,n){
        if(s[i]=='#') temp++;
        else temp--;
        ans = min(ans,temp);
    }
    cout << ans << endl;
}