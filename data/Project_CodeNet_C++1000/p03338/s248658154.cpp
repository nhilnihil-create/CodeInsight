#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int ans=0;
    rep(i,n){
        int cnt=0;

        for(char c='a';c<='z';c++){
            bool left=false,right=false;

            rep(j,i) if(s[j]==c) left=true;
            
            for(int j=i; j<n; j++) if(s[j]==c) right=true;

            if(left && right) cnt++;
        }

        if(ans<cnt) ans=cnt;
    }

    cout << ans << endl;
    
}
