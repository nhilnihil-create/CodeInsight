#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;

    int w=0;
    for(int i = 0; i < n; i++) {
        if(s[i]=='.') w++;
    }

    int b=0;
    int ans=w;
    for(int i = 0; i < n; i++) {
        if(s[i]=='#') b++;
        else w--;
        ans=min(ans,b+w);
    }
    cout << ans << "\n";
    return 0;
}