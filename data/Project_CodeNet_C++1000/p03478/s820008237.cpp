/*
      author  : nishi5451
      created : 14.08.2020 16:31:50
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i=1; i<=n; i++){
        int now = 0;
        string s;
        s = to_string(i);
        rep(j,int(s.size())) now += s[j]-'0';
        if(a<=now && now<=b) ans+=i;
    }
    cout << ans << endl;
    return 0;
}