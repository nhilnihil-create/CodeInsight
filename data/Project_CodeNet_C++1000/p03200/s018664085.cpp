#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    string s;cin >> s;
    int n=s.size();
    int w=0;
    for(int i = 0; i < n; i++) {
        if(s[n-1-i]=='B') w++;
        else break;
    }

    ll ans=0;
    int p=n-1-w;
    for(int i = p; i >=0; i--) {
        if(s[i]=='B'){
            ans += max(n-1-i-w,0) ;
            w++;
        }
    }
    cout << ans << endl;

    return 0;
}